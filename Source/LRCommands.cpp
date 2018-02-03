// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
  /*
  ==============================================================================

    LRCommands.cpp is generated by Build.lua. To make persistent changes
    to this file, edit Database.lua instead.

This file is part of MIDI2LR. Copyright 2015 by Rory Jaffe.

MIDI2LR is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

MIDI2LR is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
MIDI2LR.  If not, see <http://www.gnu.org/licenses/>.
  ==============================================================================
*/
#include "LRCommands.h"
#include "CommandMap.h"

const std::vector<std::string> LrCommandList::KeyShortcuts = {
    "Key 1",
    "Key 2",
    "Key 3",
    "Key 4",
    "Key 5",
    "Key 6",
    "Key 7",
    "Key 8",
    "Key 9",
    "Key 10",
    "Key 11",
    "Key 12",
    "Key 13",
    "Key 14",
    "Key 15",
    "Key 16",
    "Key 17",
    "Key 18",
    "Key 19",
    "Key 20",
    "Key 21",
    "Key 22",
    "Key 23",
    "Key 24",
    "Key 25",
    "Key 26",
    "Key 27",
    "Key 28",
    "Key 29",
    "Key 30",
    "Key 31",
    "Key 32",
    "Key 33",
    "Key 34",
    "Key 35",
    "Key 36",
    "Key 37",
    "Key 38",
    "Key 39",
    "Key 40",
    "Key 32 – Key 31",
    "Key 34 – Key 33",
    "Key 36 – Key 35",
    "Key 38 – Key 37",
    "Key 40 – Key 39",
};

const std::vector<std::string> LrCommandList::Filters = {
    "Library filter 1",
    "Library filter 2",
    "Library filter 3",
    "Library filter 4",
    "Library filter 5",
    "Library filter 6",
    "Library filter 7",
    "Library filter 8",
    "Library filter 9",
    "Library filter 10",
    "Library filter 11",
    "Library filter 12",
};

const std::vector<std::string> LrCommandList::General = {
    "Primary Display Grid",
    "Primary Display Loupe",
    "Primary Display Compare",
    "Primary Display Survey",
    "Enable/Disable Zoom",
    "Zoom In Some Zoom Out Some",
    "Zoom Out Some Zoom In Some",
    "Zoom In",
    "Zoom In Some",
    "Zoom Out Some",
    "Zoom Out",
    "Add to Selection Left Right",
    "Add to Selection Left",
    "Add to Selection Right",
    "Next Photo — Previous Photo",
    "Next Photo",
    "Previous Photo",
    "Series of commands 1",
    "Series of commands 2",
    "Series of commands 3",
    "Series of commands 4",
    "Series of commands 5",
    "Series of commands 6",
    "Series of commands 7",
    "Series of commands 8",
    "Series of commands 9",
};

const std::vector<std::string> LrCommandList::Library = {
    "Show Library",
    "Set Pick Flag",
    "Set Rejected Flag",
    "Unflagged",
    "0 Stars",
    "1 Star",
    "2 Stars",
    "3 Stars",
    "4 Stars",
    "5 Stars",
    "Increase Rating",
    "Decrease Rating",
    "Label Blue Enable/Disable",
    "Label Green Enable/Disable",
    "Label Red Enable/Disable",
    "Label Purple Enable/Disable",
    "Label Yellow Enable/Disable",
    "Primary Display People",
};

const std::vector<std::string> LrCommandList::Develop = {
    "Show Develop",
    "Lightroom Copy Settings",
    "Lightroom Paste Settings",
    "Create Virtual Copy",
    "Reset Settings",
    "Reset Last Modified",
    "More – Less Last Modified",
    "Increase Last Modified",
    "Decrease Last Modified",
    "More – Less",
    "More",
    "Less",
    "Redo – Undo",
    "Undo",
    "Redo",
    "Primary Display Before/After Left/Right",
    "Primary Display Before/After Top/Bottom",
    "Primary Display Before",
    "Primary Display Reference View — Left/Right",
    "Primary Display Reference View — Top/Bottom",
    "Primary Display Loupe",
};

const std::vector<std::string> LrCommandList::BasicAdjustments = {
    "Show Basic Tone",
    "White Balance As Shot",
    "White Balance Auto",
    "White Balance Cloudy",
    "White Balance Daylight",
    "White Balance Flash",
    "White Balance Fluorescent",
    "White Balance Shade",
    "White Balance Tungsten",
    "Basic Tone Auto Tone",
    "Temperature",
    "Tint",
    "Exposure",
    "Contrast",
    "Highlights (Highlight Recovery in PV2003 and PV2010)",
    "Brightness",
    "Shadows (Fill Light in PV2003 and PV2010)",
    "Whites (no effect in PV2003 and PV2010)",
    "Blacks",
    "Clarity",
    "Vibrance",
    "Saturation",
    "Reset Temperature",
    "Reset Tint",
    "Reset Exposure",
    "Reset Contrast",
    "Reset Highlights",
    "Reset Shadows",
    "Reset Whites",
    "Reset Blacks",
    "Reset Clarity",
    "Reset Vibrance",
    "Reset Saturation",
};

const std::vector<std::string> LrCommandList::ToneCurve = {
    "Show Tone Curve",
    "Dark Tones",
    "Light Tones",
    "Shadow Tones",
    "Highlight Tones",
    "Shadow Split",
    "Midtone Split",
    "Highlight Split",
    "Reset Dark Tones",
    "Reset Light Tones",
    "Reset Shadow Tones",
    "Reset Highlight Tones",
    "Reset Shadow Split",
    "Reset Midtone Split",
    "Reset Highlight Split",
    "Tone Curve Linear",
    "Tone Curve Medium Contrast",
    "Tone Curve Strong Contrast",
};

const std::vector<std::string> LrCommandList::Mixer = {
    "Show Color Adjustments",
    "Enable Color Adjustments",
    "Saturation Adjustment Red",
    "Saturation Adjustment Orange",
    "Saturation Adjustment Yellow",
    "Saturation Adjustment Green",
    "Saturation Adjustment Aqua",
    "Saturation Adjustment Blue",
    "Saturation Adjustment Purple",
    "Saturation Adjustment Magenta",
    "All Saturation Adjustment",
    "Hue Adjustment Red",
    "Hue Adjustment Orange",
    "Hue Adjustment Yellow",
    "Hue Adjustment Green",
    "Hue Adjustment Aqua",
    "Hue Adjustment Blue",
    "Hue Adjustment Purple",
    "Hue Adjustment Magenta",
    "Luminance Adjustment Red",
    "Luminance Adjustment Orange",
    "Luminance Adjustment Yellow",
    "Luminance Adjustment Green",
    "Luminance Adjustment Aqua",
    "Luminance Adjustment Blue",
    "Luminance Adjustment Purple",
    "Luminance Adjustment Magenta",
    "Convert to Grayscale",
    "Enable Grayscale Mix",
    "Gray Mixer Red",
    "Gray Mixer Orange",
    "Gray Mixer Yellow",
    "Gray Mixer Green",
    "Gray Mixer Aqua",
    "Gray Mixer Blue",
    "Gray Mixer Purple",
    "Gray Mixer Magenta",
};

const std::vector<std::string> LrCommandList::ResetMixer = {
    "Reset Saturation Adjustment Red",
    "Reset Saturation Adjustment Orange",
    "Reset Saturation Adjustment Yellow",
    "Reset Saturation Adjustment Green",
    "Reset Saturation Adjustment Aqua",
    "Reset Saturation Adjustment Blue",
    "Reset Saturation Adjustment Purple",
    "Reset Saturation Adjustment Magenta",
    "Reset All Saturation Adjustment",
    "Reset Hue Adjustment Red",
    "Reset Hue Adjustment Orange",
    "Reset Hue Adjustment Yellow",
    "Reset Hue Adjustment Green",
    "Reset Hue Adjustment Aqua",
    "Reset Hue Adjustment Blue",
    "Reset Hue Adjustment Purple",
    "Reset Hue Adjustment Magenta",
    "Reset Luminance Adjustment Red",
    "Reset Luminance Adjustment Orange",
    "Reset Luminance Adjustment Yellow",
    "Reset Luminance Adjustment Green",
    "Reset Luminance Adjustment Aqua",
    "Reset Luminance Adjustment Blue",
    "Reset Luminance Adjustment Purple",
    "Reset Luminance Adjustment Magenta",
    "Reset Gray Mixer Red",
    "Reset Gray Mixer Orange",
    "Reset Gray Mixer Yellow",
    "Reset Gray Mixer Green",
    "Reset Gray Mixer Aqua",
    "Reset Gray Mixer Blue",
    "Reset Gray Mixer Purple",
    "Reset Gray Mixer Magenta",
};

const std::vector<std::string> LrCommandList::SplitToning = {
    "Show Split Toning",
    "Enable Split Toning",
    "Shadow Hue",
    "Shadow Saturation",
    "Highlight Hue",
    "Highlight Saturation",
    "Split Toning Balance",
    "Reset Shadow Hue",
    "Reset Shadow Saturation",
    "Reset Highlight Hue",
    "Reset Highlight Saturation",
    "Reset Split Toning Balance",
};

const std::vector<std::string> LrCommandList::Detail = {
    "Show Detail",
    "Enable Detail",
    "Sharpness",
    "Sharpen Radius",
    "Sharpen Detail",
    "Sharpen Edge Masking",
    "Luminance Smoothing",
    "Luminance Detail",
    "Luminance Contrast",
    "Color Noise Reduction",
    "Color Noise Reduction Detail",
    "Color Noise Reduction Smoothness",
    "Reset Sharpness",
    "Reset Sharpen Radius",
    "Reset Sharpen Detail",
    "Reset Sharpen Edge Masking",
    "Reset Luminance Smoothing",
    "Reset Luminance Detail",
    "Reset Luminance Contrast",
    "Reset Color Noise Reduction",
    "Reset Color Noise Reduction Detail",
    "Reset Color Noise Reduction Smoothness",
};

const std::vector<std::string> LrCommandList::LensCorrections = {
    "Show Lens Corrections",
    "Enable Lens Corrections",
    "Toggle Profile Corrections",
    "Remove Chromatic Aberration",
    "Lens Profile Distortion Scale",
    "Lens Profile Chromatic Aberration Scale",
    "Lens Profile Vignetting Scale",
    "Constrain to Warp",
    "Reset Lens Profile Distortion Scale",
    "Reset Lens Profile Chromatic Aberration Scale",
    "Reset Lens Profile Vignetting Scale",
    "Defringe Purple Amount",
    "Defringe Purple Hue - Low",
    "Defringe Purple Hue - High",
    "Defringe Green Amount",
    "Defringe Green Hue - Low",
    "Defringe Green Hue - High",
    "Reset Defringe Purple Amount",
    "Reset Defringe Purple Hue - Low",
    "Reset Defringe Purple Hue - High",
    "Reset Defringe Green Amount",
    "Reset Defringe Green Hue - Low",
    "Reset Defringe Green Hue - High",
    "Lens Manual Distortion Amount",
    "Vignette Amount",
    "Vignette Midpoint",
    "Reset Lens Manual Distortion Amount",
    "Reset Vignette Amount",
    "Reset Vignette Midpoint",
};

const std::vector<std::string> LrCommandList::Transform = {
    "Show Transform",
    "Enable Transform",
    "Perspective Correction Off",
    "Perspective Correction Auto",
    "Perspective Correction Level",
    "Perspective Correction Vertical",
    "Perspective Correction Guided",
    "Perspective Correction Full",
    "Reset Upright Settings",
    "Perspective Vertical",
    "Perspective Horizontal",
    "Perspective Rotate",
    "Perspective Scale",
    "Perspective Aspect",
    "Perspective X",
    "Perspective Y",
    "Reset Perspective Vertical",
    "Reset Perspective Horizontal",
    "Reset Perspective Rotate",
    "Reset Perspective Scale",
    "Reset Perspective Aspect",
    "Reset Perspective X",
    "Reset Perspective Y",
};

const std::vector<std::string> LrCommandList::Effects = {
    "Show Effects",
    "Enable Effects",
    "Dehaze Amount",
    "Post Crop Vignette Amount",
    "Post Crop Vignette Midpoint",
    "Post Crop Vignette Feather",
    "Post Crop Vignette Roundness",
    "Post Crop Vignette Style",
    "Highlight Priority",
    "Color Priority",
    "Paint Overlay",
    "Post Crop Vignette Highlight Contrast",
    "Grain Amount",
    "Grain Size",
    "Grain Roughness",
    "Reset Dehaze Amount",
    "Reset Post Crop Vignette Amount",
    "Reset Post Crop Vignette Midpoint",
    "Reset Post Crop Vignette Feather",
    "Reset Post Crop Vignette Roundness",
    "Reset Post Crop Vignette Style",
    "Reset Post Crop Vignette Highlight Contrast",
    "Reset Grain Amount",
    "Reset Grain Size",
    "Reset Grain Roughness",
};

const std::vector<std::string> LrCommandList::Calibration = {
    "Show Calibration",
    "Enable Calibration",
    "Adobe Standard",
    "Camera Clear",
    "Camera Darker Skin Tone",
    "Camera Deep",
    "Camera Faithful",
    "Camera Flat",
    "Camera Landscape",
    "Camera Light",
    "Camera Lighter Skin Tone",
    "Camera Monochrome",
    "Camera Monotone",
    "Camera Muted",
    "Camera Natural",
    "Camera Neutral",
    "Camera Portrait",
    "Camera Positive Film",
    "Camera Standard",
    "Camera Vivid",
    "Camera Vivid Blue",
    "Camera Vivid Green",
    "Camera Vivid Red",
    "Shadow Tint Calibration",
    "Red Hue Calibration",
    "Red Saturation Calibration",
    "Green Hue Calibration",
    "Green Saturation Calibration",
    "Blue Hue Calibration",
    "Blue Saturation Calibration",
    "Reset Shadow Tint Calibration",
    "Reset Red Hue Calibration",
    "Reset Red Saturation Calibration",
    "Reset Green Hue Calibration",
    "Reset Green Saturation Calibration",
    "Reset Blue Hue Calibration",
    "Reset Blue Saturation Calibration",
};

const std::vector<std::string> LrCommandList::DevelopPresets = {
    "Develop Preset 1",
    "Develop Preset 2",
    "Develop Preset 3",
    "Develop Preset 4",
    "Develop Preset 5",
    "Develop Preset 6",
    "Develop Preset 7",
    "Develop Preset 8",
    "Develop Preset 9",
    "Develop Preset 10",
    "Develop Preset 11",
    "Develop Preset 12",
    "Develop Preset 13",
    "Develop Preset 14",
    "Develop Preset 15",
    "Develop Preset 16",
    "Develop Preset 17",
    "Develop Preset 18",
    "Develop Preset 19",
    "Develop Preset 20",
    "Develop Preset 21",
    "Develop Preset 22",
    "Develop Preset 23",
    "Develop Preset 24",
    "Develop Preset 25",
    "Develop Preset 26",
    "Develop Preset 27",
    "Develop Preset 28",
    "Develop Preset 29",
    "Develop Preset 30",
    "Develop Preset 31",
    "Develop Preset 32",
    "Develop Preset 33",
    "Develop Preset 34",
    "Develop Preset 35",
    "Develop Preset 36",
    "Develop Preset 37",
    "Develop Preset 38",
    "Develop Preset 39",
    "Develop Preset 40",
    "Develop Preset 41",
    "Develop Preset 42",
    "Develop Preset 43",
    "Develop Preset 44",
    "Develop Preset 45",
    "Develop Preset 46",
    "Develop Preset 47",
    "Develop Preset 48",
    "Develop Preset 49",
    "Develop Preset 50",
    "Develop Preset 51",
    "Develop Preset 52",
    "Develop Preset 53",
    "Develop Preset 54",
    "Develop Preset 55",
    "Develop Preset 56",
    "Develop Preset 57",
    "Develop Preset 58",
    "Develop Preset 59",
    "Develop Preset 60",
    "Develop Preset 61",
    "Develop Preset 62",
    "Develop Preset 63",
    "Develop Preset 64",
    "Develop Preset 65",
    "Develop Preset 66",
    "Develop Preset 67",
    "Develop Preset 68",
    "Develop Preset 69",
    "Develop Preset 70",
    "Develop Preset 71",
    "Develop Preset 72",
    "Develop Preset 73",
    "Develop Preset 74",
    "Develop Preset 75",
    "Develop Preset 76",
    "Develop Preset 77",
    "Develop Preset 78",
    "Develop Preset 79",
    "Develop Preset 80",
};

const std::vector<std::string> LrCommandList::Keywords = {
    "Keyword 1",
    "Keyword 2",
    "Keyword 3",
    "Keyword 4",
    "Keyword 5",
    "Keyword 6",
    "Keyword 7",
    "Keyword 8",
    "Keyword 9",
    "Keyword 10",
    "Keyword 11",
    "Keyword 12",
    "Keyword 13",
    "Keyword 14",
    "Keyword 15",
    "Keyword 16",
};

const std::vector<std::string> LrCommandList::LocalAdjustments = {
    "Show Graduated Filters",
    "Show Radial Filters",
    "Show Red-Eye Correction",
    "Show Spot Removal",
    "Show Brush Adjustments",
    "Brush — Size",
    "Brush — Size — smaller",
    "Brush — Size — larger",
    "Brush — Feather",
    "Brush — Feather — smaller",
    "Brush — Feather — larger",
    "Local Adjustments Temp. (PV2012)",
    "Local Adjustments Tint (PV2012)",
    "Local Adjustments Exposure (PV2010 and PV2012)",
    "Local Adjustments Contrast (PV2010 and PV2012)",
    "Local Adjustments Highlights (PV2012)",
    "Local Adjustments Shadows (PV2012)",
    "Local Adjustments Whites (PV2012)",
    "Local Adjustments Blacks (PV2012)",
    "Local Adjustments Clarity (PV2010 and PV2012)",
    "Local Adjustments Dehaze (PV2012)",
    "Local Adjustments Saturation (PV2010 and PV2012)",
    "Local Adjustments Sharpness (PV2010 and PV2012)",
    "Local Adjustments Luminence Noise Reduction (PV2012)",
    "Local Adjustments Moire (PV2012)",
    "Local Adjustments Defringe (PV2012)",
    "Local Toning Luminance (PV2010)",
    "Reset Local Adjustments Temp. (PV2012)",
    "Reset Local Adjustments Tint (PV2012)",
    "Reset Local Adjustments Exposure (PV2010 and PV2012)",
    "Reset Local Adjustments Contrast (PV2010 and PV2012)",
    "Reset Local Adjustments Highlights (PV2012)",
    "Reset Local Adjustments Shadows (PV2012)",
    "Reset Local Adjustments Whites (PV2012)",
    "Reset Local Adjustments Blacks (PV2012)",
    "Reset Local Adjustments Clarity (PV2010 and PV2012)",
    "Reset Local Adjustments Dehaze (PV2012)",
    "Reset Local Adjustments Saturation (PV2010 and PV2012)",
    "Reset Local Adjustments Sharpness (PV2010 and PV2012)",
    "Reset Local Adjustments Luminence Noise Reduction (PV2012)",
    "Reset Local Adjustments Moire (PV2012)",
    "Reset Local Adjustments Defringe (PV2012)",
    "Reset Local Toning Luminance (PV2010)",
    "Enable Radial Filter",
    "Enable Graduated Filter",
    "Enable Brush Adjustments",
    "Enable Red-Eye",
    "Enable Spot Removal",
    "Reset Radial Filters",
    "Reset Graduated Filters",
    "Reset Brush Corrections",
    "Reset Red-Eye",
    "Reset Spot Removal",
    "Show Mask Overlay",
    "Overlay Color",
    "Local adjustments presets 1",
    "Local adjustments presets 2",
    "Local adjustments presets 3",
    "Local adjustments presets 4",
    "Local adjustments presets 5",
    "Local adjustments presets 6",
    "Local adjustments presets 7",
    "Local adjustments presets 8",
    "Local adjustments presets 9",
    "Local adjustments presets 10",
    "Local adjustments presets 11",
    "Local adjustments presets 12",
    "Local adjustments presets 13",
    "Local adjustments presets 14",
    "Local adjustments presets 15",
    "Local adjustments presets 16",
};

const std::vector<std::string> LrCommandList::Crop = {
    "Straighten Angle",
    "Crop Angle",
    "Crop - Bottom",
    "Crop - Left",
    "Crop - Right",
    "Crop - Top",
    "Reset Crop",
    "Reset Straighten Angle",
    "Show Crop",
};

const std::vector<std::string> LrCommandList::ToolModulePanel = {
    "Show Loupe",
    "Show Map",
    "Show Book",
    "Show Slideshow",
    "Show Print",
    "Show Web",
};

const std::vector<std::string> LrCommandList::SecondaryDisplay = {
    "Secondary Display Loupe",
    "Secondary Display Live Loupe",
    "Secondary Display Locked Loupe",
    "Secondary Display Grid",
    "Secondary Display Compare",
    "Secondary Display Survey",
    "Secondary Display Slideshow",
    "Secondary Display Show",
};

const std::vector<std::string> LrCommandList::ProgramProfiles = {
    "Profile: 1",
    "Profile: 2",
    "Profile: 3",
    "Profile: 4",
    "Profile: 5",
    "Profile: 6",
    "Profile: 7",
    "Profile: 8",
    "Profile: 9",
    "Profile: 10",
    "Manual Update",
};

const std::vector<std::string> LrCommandList::LrStringList = {
    "Unmapped",
    /* Keyboard Shortcuts for User */
    "Key1",
    "Key2",
    "Key3",
    "Key4",
    "Key5",
    "Key6",
    "Key7",
    "Key8",
    "Key9",
    "Key10",
    "Key11",
    "Key12",
    "Key13",
    "Key14",
    "Key15",
    "Key16",
    "Key17",
    "Key18",
    "Key19",
    "Key20",
    "Key21",
    "Key22",
    "Key23",
    "Key24",
    "Key25",
    "Key26",
    "Key27",
    "Key28",
    "Key29",
    "Key30",
    "Key31",
    "Key32",
    "Key33",
    "Key34",
    "Key35",
    "Key36",
    "Key37",
    "Key38",
    "Key39",
    "Key40",
    "Key32Key31",
    "Key34Key33",
    "Key36Key35",
    "Key38Key37",
    "Key40Key39",
    /* Library filter */
    "Filter_1",
    "Filter_2",
    "Filter_3",
    "Filter_4",
    "Filter_5",
    "Filter_6",
    "Filter_7",
    "Filter_8",
    "Filter_9",
    "Filter_10",
    "Filter_11",
    "Filter_12",
    /* General */
    "ShoVwgrid",
    "ShoVwloupe",
    "ShoVwcompare",
    "ShoVwsurvey",
    "ToggleZoomOffOn",
    "ZoomInOut",
    "ZoomOutIn",
    "ZoomInLargeStep",
    "ZoomInSmallStep",
    "ZoomOutSmallStep",
    "ZoomOutLargeStep",
    "SelectRightLeft",
    "Select1Left",
    "Select1Right",
    "NextPrev",
    "Next",
    "Prev",
    "ActionSeries1",
    "ActionSeries2",
    "ActionSeries3",
    "ActionSeries4",
    "ActionSeries5",
    "ActionSeries6",
    "ActionSeries7",
    "ActionSeries8",
    "ActionSeries9",
    /* Library */
    "SwToMlibrary",
    "Pick",
    "Reject",
    "RemoveFlag",
    "SetRating0",
    "SetRating1",
    "SetRating2",
    "SetRating3",
    "SetRating4",
    "SetRating5",
    "IncreaseRating",
    "DecreaseRating",
    "ToggleBlue",
    "ToggleGreen",
    "ToggleRed",
    "TogglePurple",
    "ToggleYellow",
    "ShoVwpeople",
    /* Develop */
    "SwToMdevelop",
    "LRCopy",
    "LRPaste",
    "VirtualCopy",
    "ResetAll",
    "ResetLast",
    "ChangeLastDevelopParameter",
    "IncrementLastDevelopParameter",
    "DecrementLastDevelopParameter",
    "ChangeCurrentSlider",
    "SliderIncrease",
    "SliderDecrease",
    "RedoUndo",
    "Undo",
    "Redo",
    "ShoVwdevelop_before_after_horiz",
    "ShoVwdevelop_before_after_vert",
    "ShoVwdevelop_before",
    "ShoVwRefHoriz",
    "ShoVwRefVert",
    "ShoVwdevelop_loupe",
    /* Basic Tone */
    "RevealPanelAdjust",
    "WhiteBalanceAs_Shot",
    "WhiteBalanceAuto",
    "WhiteBalanceCloudy",
    "WhiteBalanceDaylight",
    "WhiteBalanceFlash",
    "WhiteBalanceFluorescent",
    "WhiteBalanceShade",
    "WhiteBalanceTungsten",
    "AutoTone",
    "Temperature",
    "Tint",
    "Exposure",
    "Contrast",
    "Highlights",
    "Brightness",
    "Shadows",
    "Whites",
    "Blacks",
    "Clarity",
    "Vibrance",
    "Saturation",
    "ResetTemperature",
    "ResetTint",
    "ResetExposure",
    "ResetContrast",
    "ResetHighlights",
    "ResetShadows",
    "ResetWhites",
    "ResetBlacks",
    "ResetClarity",
    "ResetVibrance",
    "ResetSaturation",
    /* Tone Curve */
    "RevealPanelTone",
    "ParametricDarks",
    "ParametricLights",
    "ParametricShadows",
    "ParametricHighlights",
    "ParametricShadowSplit",
    "ParametricMidtoneSplit",
    "ParametricHighlightSplit",
    "ResetParametricDarks",
    "ResetParametricLights",
    "ResetParametricShadows",
    "ResetParametricHighlights",
    "ResetParametricShadowSplit",
    "ResetParametricMidtoneSplit",
    "ResetParametricHighlightSplit",
    "PointCurveLinear",
    "PointCurveMediumContrast",
    "PointCurveStrongContrast",
    /* Color Adjustments */
    "RevealPanelMixer",
    "EnableColorAdjustments",
    "SaturationAdjustmentRed",
    "SaturationAdjustmentOrange",
    "SaturationAdjustmentYellow",
    "SaturationAdjustmentGreen",
    "SaturationAdjustmentAqua",
    "SaturationAdjustmentBlue",
    "SaturationAdjustmentPurple",
    "SaturationAdjustmentMagenta",
    "AllSaturationAdjustment",
    "HueAdjustmentRed",
    "HueAdjustmentOrange",
    "HueAdjustmentYellow",
    "HueAdjustmentGreen",
    "HueAdjustmentAqua",
    "HueAdjustmentBlue",
    "HueAdjustmentPurple",
    "HueAdjustmentMagenta",
    "LuminanceAdjustmentRed",
    "LuminanceAdjustmentOrange",
    "LuminanceAdjustmentYellow",
    "LuminanceAdjustmentGreen",
    "LuminanceAdjustmentAqua",
    "LuminanceAdjustmentBlue",
    "LuminanceAdjustmentPurple",
    "LuminanceAdjustmentMagenta",
    "ConvertToGrayscale",
    "EnableGrayscaleMix",
    "GrayMixerRed",
    "GrayMixerOrange",
    "GrayMixerYellow",
    "GrayMixerGreen",
    "GrayMixerAqua",
    "GrayMixerBlue",
    "GrayMixerPurple",
    "GrayMixerMagenta",
    /* Reset Color Adjustments */
    "ResetSaturationAdjustmentRed",
    "ResetSaturationAdjustmentOrange",
    "ResetSaturationAdjustmentYellow",
    "ResetSaturationAdjustmentGreen",
    "ResetSaturationAdjustmentAqua",
    "ResetSaturationAdjustmentBlue",
    "ResetSaturationAdjustmentPurple",
    "ResetSaturationAdjustmentMagenta",
    "ResetAllSaturationAdjustment",
    "ResetHueAdjustmentRed",
    "ResetHueAdjustmentOrange",
    "ResetHueAdjustmentYellow",
    "ResetHueAdjustmentGreen",
    "ResetHueAdjustmentAqua",
    "ResetHueAdjustmentBlue",
    "ResetHueAdjustmentPurple",
    "ResetHueAdjustmentMagenta",
    "ResetLuminanceAdjustmentRed",
    "ResetLuminanceAdjustmentOrange",
    "ResetLuminanceAdjustmentYellow",
    "ResetLuminanceAdjustmentGreen",
    "ResetLuminanceAdjustmentAqua",
    "ResetLuminanceAdjustmentBlue",
    "ResetLuminanceAdjustmentPurple",
    "ResetLuminanceAdjustmentMagenta",
    "ResetGrayMixerRed",
    "ResetGrayMixerOrange",
    "ResetGrayMixerYellow",
    "ResetGrayMixerGreen",
    "ResetGrayMixerAqua",
    "ResetGrayMixerBlue",
    "ResetGrayMixerPurple",
    "ResetGrayMixerMagenta",
    /* Split Toning */
    "RevealPanelSplit",
    "EnableSplitToning",
    "SplitToningShadowHue",
    "SplitToningShadowSaturation",
    "SplitToningHighlightHue",
    "SplitToningHighlightSaturation",
    "SplitToningBalance",
    "ResetSplitToningShadowHue",
    "ResetSplitToningShadowSaturation",
    "ResetSplitToningHighlightHue",
    "ResetSplitToningHighlightSaturation",
    "ResetSplitToningBalance",
    /* Detail */
    "RevealPanelDetail",
    "EnableDetail",
    "Sharpness",
    "SharpenRadius",
    "SharpenDetail",
    "SharpenEdgeMasking",
    "LuminanceSmoothing",
    "LuminanceNoiseReductionDetail",
    "LuminanceNoiseReductionContrast",
    "ColorNoiseReduction",
    "ColorNoiseReductionDetail",
    "ColorNoiseReductionSmoothness",
    "ResetSharpness",
    "ResetSharpenRadius",
    "ResetSharpenDetail",
    "ResetSharpenEdgeMasking",
    "ResetLuminanceSmoothing",
    "ResetLuminanceNoiseReductionDetail",
    "ResetLuminanceNoiseReductionContrast",
    "ResetColorNoiseReduction",
    "ResetColorNoiseReductionDetail",
    "ResetColorNoiseReductionSmoothness",
    /* Lens Corrections */
    "RevealPanelLens",
    "EnableLensCorrections",
    "LensProfileEnable",
    "AutoLateralCA",
    "LensProfileDistortionScale",
    "LensProfileChromaticAberrationScale",
    "LensProfileVignettingScale",
    "CropConstrainToWarp",
    "ResetLensProfileDistortionScale",
    "ResetLensProfileChromaticAberrationScale",
    "ResetLensProfileVignettingScale",
    "DefringePurpleAmount",
    "DefringePurpleHueLo",
    "DefringePurpleHueHi",
    "DefringeGreenAmount",
    "DefringeGreenHueLo",
    "DefringeGreenHueHi",
    "ResetDefringePurpleAmount",
    "ResetDefringePurpleHueLo",
    "ResetDefringePurpleHueHi",
    "ResetDefringeGreenAmount",
    "ResetDefringeGreenHueLo",
    "ResetDefringeGreenHueHi",
    "LensManualDistortionAmount",
    "VignetteAmount",
    "VignetteMidpoint",
    "ResetLensManualDistortionAmount",
    "ResetVignetteAmount",
    "ResetVignetteMidpoint",
    /* Transform */
    "RevealPanelTransform",
    "EnableTransform",
    "UprightOff",
    "UprightAuto",
    "UprightLevel",
    "UprightVertical",
    "UprightGuided",
    "UprightFull",
    "ResetPerspectiveUpright",
    "PerspectiveVertical",
    "PerspectiveHorizontal",
    "PerspectiveRotate",
    "PerspectiveScale",
    "PerspectiveAspect",
    "PerspectiveX",
    "PerspectiveY",
    "ResetPerspectiveVertical",
    "ResetPerspectiveHorizontal",
    "ResetPerspectiveRotate",
    "ResetPerspectiveScale",
    "ResetPerspectiveAspect",
    "ResetPerspectiveX",
    "ResetPerspectiveY",
    /* Effects */
    "RevealPanelEffects",
    "EnableEffects",
    "Dehaze",
    "PostCropVignetteAmount",
    "PostCropVignetteMidpoint",
    "PostCropVignetteFeather",
    "PostCropVignetteRoundness",
    "PostCropVignetteStyle",
    "PostCropVignetteStyleHighlightPriority",
    "PostCropVignetteStyleColorPriority",
    "PostCropVignetteStylePaintOverlay",
    "PostCropVignetteHighlightContrast",
    "GrainAmount",
    "GrainSize",
    "GrainFrequency",
    "ResetDehaze",
    "ResetPostCropVignetteAmount",
    "ResetPostCropVignetteMidpoint",
    "ResetPostCropVignetteFeather",
    "ResetPostCropVignetteRoundness",
    "ResetPostCropVignetteStyle",
    "ResetPostCropVignetteHighlightContrast",
    "ResetGrainAmount",
    "ResetGrainSize",
    "ResetGrainFrequency",
    /* Calibration */
    "RevealPanelCalibrate",
    "EnableCalibration",
    "Profile_Adobe_Standard",
    "Profile_Camera_Clear",
    "Profile_Camera_Darker_Skin_Tone",
    "Profile_Camera_Deep",
    "Profile_Camera_Faithful",
    "Profile_Camera_Flat",
    "Profile_Camera_Landscape",
    "Profile_Camera_Light",
    "Profile_Camera_Lighter_Skin_Tone",
    "Profile_Camera_Monochrome",
    "Profile_Camera_Monotone",
    "Profile_Camera_Muted",
    "Profile_Camera_Natural",
    "Profile_Camera_Neutral",
    "Profile_Camera_Portrait",
    "Profile_Camera_Positive_Film",
    "Profile_Camera_Standard",
    "Profile_Camera_Vivid",
    "Profile_Camera_Vivid_Blue",
    "Profile_Camera_Vivid_Green",
    "Profile_Camera_Vivid_Red",
    "ShadowTint",
    "RedHue",
    "RedSaturation",
    "GreenHue",
    "GreenSaturation",
    "BlueHue",
    "BlueSaturation",
    "ResetShadowTint",
    "ResetRedHue",
    "ResetRedSaturation",
    "ResetGreenHue",
    "ResetGreenSaturation",
    "ResetBlueHue",
    "ResetBlueSaturation",
    /* Develop Presets */
    "Preset_1",
    "Preset_2",
    "Preset_3",
    "Preset_4",
    "Preset_5",
    "Preset_6",
    "Preset_7",
    "Preset_8",
    "Preset_9",
    "Preset_10",
    "Preset_11",
    "Preset_12",
    "Preset_13",
    "Preset_14",
    "Preset_15",
    "Preset_16",
    "Preset_17",
    "Preset_18",
    "Preset_19",
    "Preset_20",
    "Preset_21",
    "Preset_22",
    "Preset_23",
    "Preset_24",
    "Preset_25",
    "Preset_26",
    "Preset_27",
    "Preset_28",
    "Preset_29",
    "Preset_30",
    "Preset_31",
    "Preset_32",
    "Preset_33",
    "Preset_34",
    "Preset_35",
    "Preset_36",
    "Preset_37",
    "Preset_38",
    "Preset_39",
    "Preset_40",
    "Preset_41",
    "Preset_42",
    "Preset_43",
    "Preset_44",
    "Preset_45",
    "Preset_46",
    "Preset_47",
    "Preset_48",
    "Preset_49",
    "Preset_50",
    "Preset_51",
    "Preset_52",
    "Preset_53",
    "Preset_54",
    "Preset_55",
    "Preset_56",
    "Preset_57",
    "Preset_58",
    "Preset_59",
    "Preset_60",
    "Preset_61",
    "Preset_62",
    "Preset_63",
    "Preset_64",
    "Preset_65",
    "Preset_66",
    "Preset_67",
    "Preset_68",
    "Preset_69",
    "Preset_70",
    "Preset_71",
    "Preset_72",
    "Preset_73",
    "Preset_74",
    "Preset_75",
    "Preset_76",
    "Preset_77",
    "Preset_78",
    "Preset_79",
    "Preset_80",
    /* Keywords */
    "Keyword1",
    "Keyword2",
    "Keyword3",
    "Keyword4",
    "Keyword5",
    "Keyword6",
    "Keyword7",
    "Keyword8",
    "Keyword9",
    "Keyword10",
    "Keyword11",
    "Keyword12",
    "Keyword13",
    "Keyword14",
    "Keyword15",
    "Keyword16",
    /* Local Adjustments */
    "GraduatedFilter",
    "RadialFilter",
    "RedEye",
    "SpotRemoval",
    "AdjustmentBrush",
    "ChangeBrushSize",
    "BrushSizeSmaller",
    "BrushSizeLarger",
    "ChangeFeatherSize",
    "BrushFeatherSmaller",
    "BrushFeatherLarger",
    "local_Temperature",
    "local_Tint",
    "local_Exposure",
    "local_Contrast",
    "local_Highlights",
    "local_Shadows",
    "local_Whites2012",
    "local_Blacks2012",
    "local_Clarity",
    "local_Dehaze",
    "local_Saturation",
    "local_Sharpness",
    "local_LuminanceNoise",
    "local_Moire",
    "local_Defringe",
    "local_ToningLuminance",
    "Resetlocal_Temperature",
    "Resetlocal_Tint",
    "Resetlocal_Exposure",
    "Resetlocal_Contrast",
    "Resetlocal_Highlights",
    "Resetlocal_Shadows",
    "Resetlocal_Whites2012",
    "Resetlocal_Blacks2012",
    "Resetlocal_Clarity",
    "Resetlocal_Dehaze",
    "Resetlocal_Saturation",
    "Resetlocal_Sharpness",
    "Resetlocal_LuminanceNoise",
    "Resetlocal_Moire",
    "Resetlocal_Defringe",
    "Resetlocal_ToningLuminance",
    "EnableCircularGradientBasedCorrections",
    "EnableGradientBasedCorrections",
    "EnablePaintBasedCorrections",
    "EnableRedEye",
    "EnableRetouch",
    "ResetCircGrad",
    "ResetGradient",
    "ResetBrushing",
    "ResetRedeye",
    "ResetSpotRem",
    "ShowMaskOverlay",
    "CycleMaskOverlayColor",
    "LocalPreset1",
    "LocalPreset2",
    "LocalPreset3",
    "LocalPreset4",
    "LocalPreset5",
    "LocalPreset6",
    "LocalPreset7",
    "LocalPreset8",
    "LocalPreset9",
    "LocalPreset10",
    "LocalPreset11",
    "LocalPreset12",
    "LocalPreset13",
    "LocalPreset14",
    "LocalPreset15",
    "LocalPreset16",
    /* Crop */
    "straightenAngle",
    "CropAngle",
    "CropBottom",
    "CropLeft",
    "CropRight",
    "CropTop",
    "ResetCrop",
    "ResetstraightenAngle",
    "CropOverlay",
    /* Select Tools, Modules and Panels */
    "Loupe",
    "SwToMmap",
    "SwToMbook",
    "SwToMslideshow",
    "SwToMprint",
    "SwToMweb",
    /* Secondary Display */
    "ShoScndVwloupe",
    "ShoScndVwlive_loupe",
    "ShoScndVwlocked_loupe",
    "ShoScndVwgrid",
    "ShoScndVwcompare",
    "ShoScndVwsurvey",
    "ShoScndVwslideshow",
    "ToggleScreenTwo",
    /* Profiles */
    "profile1",
    "profile2",
    "profile3",
    "profile4",
    "profile5",
    "profile6",
    "profile7",
    "profile8",
    "profile9",
    "profile10",
    "FullRefresh",
};

const std::vector <std::string> LrCommandList::NextPrevProfile = {
    "Previous Profile",
    "Next Profile",
};

size_t LrCommandList::GetIndexOfCommand(const std::string& command)
{
    static std::unordered_map<std::string, size_t> indexMap;

    // better to check for empty then length, as empty has a constant run time behavior.
    if (indexMap.empty()) {
        size_t idx = 0;
        for (const auto& str : LrStringList)
            indexMap[str] = idx++;

        for (const auto& str : NextPrevProfile)
            indexMap[str] = idx++;
    }

    return indexMap[command];
}