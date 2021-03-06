/*
 * This file is part of MIDI2LR. Copyright (C) 2015 by Rory Jaffe.
 *
 * MIDI2LR is free software: you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * MIDI2LR is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with MIDI2LR.  If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

 /* the following is adapted from https://github.com/microsoft/node-native-keymap/blob/master/src/keyboard_mac.mm */
#include "Ocpp.h"
#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>
#include <cctype>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <optional>
#include <thread>
#include <fmt/format.h>
#include <JuceLibraryCode/JuceHeader.h>
#include "DebugInfo.h"
#include "Misc.h"

/* note that, in MacOS Catalina, TISGetInputSourceProperty() must execute on the main thread, or crash */

namespace {
   std::optional<std::pair<bool, UniChar>> ConvertKeyCodeToText(
       const UCKeyboardLayout* keyboardLayout, UInt16 virtual_key_code, UInt32 modifiers)
   {
      /* Note that modifiers are the eventrecord modifiers >> 8 & 0xFF. So shift is 0x2.*/
      UInt32 dead_key_state = 0;
      UniCharCount char_count = 0;
      UniChar character = 0;
      OSStatus status = UCKeyTranslate(keyboardLayout, virtual_key_code, kUCKeyActionDown,
          modifiers, LMGetKbdLast(), kUCKeyTranslateNoDeadKeysBit, &dead_key_state, 1, &char_count,
          &character);

      bool isDeadKey = false;
      if (status == noErr && char_count == 0 && dead_key_state != 0) {
         isDeadKey = true;
         status = UCKeyTranslate(keyboardLayout, virtual_key_code, kUCKeyActionDown, modifiers,
             LMGetKbdLast(), kUCKeyTranslateNoDeadKeysBit, &dead_key_state, 1, &char_count,
             &character);
      }

      if (status == noErr && char_count == 1 && !std::iscntrl(character))
         return std::make_pair(isDeadKey, character);
      return {};
   }

   std::shared_mutex mtx; /* since following are filled in in Message Loop asynchronously */
   std::string sourceIdString;
   std::string localizedNameString;
   std::string langString;
   std::unordered_map<UniChar, std::pair<size_t, bool>> KeyMapA{};

   void FillInMessageLoop()
   {
      std::unique_lock lock(mtx);
      TISInputSourceRef source = TISCopyCurrentKeyboardInputSource();
      if (!source)
         source = TISCopyCurrentKeyboardLayoutInputSource();
      if (!source) {
         rsj::LogAndAlertError(
             juce::translate("Invalid keyboard layout handle."), "Invalid keyboard layout handle.");
         return;
      }
      CFStringRef sourceId =
          (CFStringRef)TISGetInputSourceProperty(source, kTISPropertyInputSourceID);
      if (sourceId)
         sourceIdString = std::string(((NSString*)sourceId).UTF8String);

      CFStringRef localizedName =
          (CFStringRef)TISGetInputSourceProperty(source, kTISPropertyLocalizedName);
      if (localizedName)
         localizedNameString = std::string(((NSString*)localizedName).UTF8String);

      NSArray* languages =
          (NSArray*)TISGetInputSourceProperty(source, kTISPropertyInputSourceLanguages);
      if (languages && languages.count > 0) {
         NSString* lang = languages[0];
         if (lang)
            langString = std::string(lang.UTF8String);
      }

      /* get layout data here since it's before use is needed and it crashes if done on another
       * thread since MacOS Catalina. it must happen on the main message thread */
      CFDataRef layout_data = static_cast<CFDataRef>(
          (TISGetInputSourceProperty(source, kTISPropertyUnicodeKeyLayoutData)));
      if (!layout_data) {
         // TISGetInputSourceProperty returns null with  Japanese keyboard layout.
         // Using TISCopyCurrentKeyboardLayoutInputSource to fix NULL return.
         TISInputSourceRef sourcea = TISCopyCurrentKeyboardLayoutInputSource();
         if (sourcea) {
            layout_data = static_cast<CFDataRef>(
                (TISGetInputSourceProperty(sourcea, kTISPropertyUnicodeKeyLayoutData)));
            CFRelease(sourcea);
         }
      }
      if (!layout_data) {
         rsj::LogAndAlertError(
             juce::translate("Invalid keyboard layout handle."), "Invalid keyboard layout handle.");
         return;
      }
      const UCKeyboardLayout* keyboardLayout =
          reinterpret_cast<const UCKeyboardLayout*>(CFDataGetBytePtr(layout_data));
      if (!keyboardLayout)
         rsj::LogAndAlertError(
             juce::translate("Invalid keyboard layout handle."), "Invalid keyboard layout handle.");
      else
         for (UInt16 native_keycode = 0; native_keycode <= 0xFF; ++native_keycode) {
            if (auto value = ConvertKeyCodeToText(keyboardLayout, native_keycode, 0))
               KeyMapA.try_emplace(value->second, std::make_pair(native_keycode, false));
            if (auto value = ConvertKeyCodeToText(keyboardLayout, native_keycode, 2))
               KeyMapA.try_emplace(value->second, std::make_pair(native_keycode, true));
         }
      CFRelease(source);
   }

   bool FillInSucceeded()
   {
      std::shared_lock lock(mtx);
      return !KeyMapA.empty();
   }

   std::string GetKeyboardLayout()
   {
      std::shared_lock lock(mtx);
      std::string result;
      if (!sourceIdString.empty())
         result = "Id " + sourceIdString;
      if (!localizedNameString.empty())
         result += ". Localized name = " + localizedNameString;
      if (!langString.empty())
         result += ". Language = " + langString;
      return result;
   }

   std::unordered_map<UniChar, std::pair<size_t, bool>> InternalKeyMap() {
      std::shared_lock lock(mtx);
      return KeyMapA;
   }
} // namespace

std::unordered_map<UniChar, std::pair<size_t, bool>> rsj::GetKeyMap()
{
   using namespace std::chrono_literals;
   if (!FillInSucceeded() && !juce::MessageManager::callAsync(FillInMessageLoop))
      rsj::Log("Unable to post FillInMessageLoop to message queue.");
   for (int i = 0; i < 4; ++i) {
      if (FillInSucceeded())
         break;
      std::this_thread::sleep_for(20ms);
      rsj::Log("20ms sleep for message queue.");
   }
   rsj::Log(fmt::format(
       "Making KeyMap. Keyboard type {}. KeyMap is {}", GetKeyboardLayout(), FillInSucceeded()));
   return InternalKeyMap();
}
