// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <scalefinder/chord_quals.h>
#include <scalefinder/engine.h>
#include <scalefinder/piano_key.h>

#include "cinder/audio/Context.h"
#include "cinder/audio/GainNode.h"
#include "cinder/audio/GenNode.h"

namespace myapp {

using scalefinder::ChordQual;

// Used in drawing the keyboard
const int kWhiteKeyHeight = 150;
const int kWhiteKeyWidth = 30;
const int kBlackKeyHeight = 100;
const int kBlackKeyWidth = 20;
const int pianox = 200;
const int pianoy = 600;

class MyApp : public cinder::app::App {
 public:
  // For some reason, it wouldn't let me place kQualsMap and kPianoKeys
  // outside of this spot.
  std::map<std::string, ChordQual> kQualsMap = {
      {"M", ChordQual::kMajor},          {"m", ChordQual::kMinor},
      {"o", ChordQual::kDiminished},     {"+", ChordQual::kAugmented},
      {"0", ChordQual::kHalfDiminished}, {"dom", ChordQual::kDominant}};

  std::vector<scalefinder::PianoKey> kPianoKeys = {
      scalefinder::PianoKey("C4", 60, 0, true),
      scalefinder::PianoKey("C#4", 61, 15, false),
      scalefinder::PianoKey("D4", 62, 30, true),
      scalefinder::PianoKey("D#4", 63, 45, false),
      scalefinder::PianoKey("E4", 64, 60, true),
      scalefinder::PianoKey("F4", 65, 90, true),
      scalefinder::PianoKey("F#4", 66, 105, false),
      scalefinder::PianoKey("G4", 67, 120, true),
      scalefinder::PianoKey("G#4", 68, 135, false),
      scalefinder::PianoKey("A4", 69, 150, true),
      scalefinder::PianoKey("A#4", 70, 165, false),
      scalefinder::PianoKey("B4", 71, 180, true),

      scalefinder::PianoKey("C5", 72, 210, true),
      scalefinder::PianoKey("C#5", 73, 225, false),
      scalefinder::PianoKey("D5", 74, 240, true),
      scalefinder::PianoKey("D#5", 75, 255, false),
      scalefinder::PianoKey("E5", 76, 270, true),
      scalefinder::PianoKey("F5", 77, 300, true),
      scalefinder::PianoKey("F#5", 78, 315, false),
      scalefinder::PianoKey("G5", 79, 330, true),
      scalefinder::PianoKey("G#5", 80, 345, false),
      scalefinder::PianoKey("A5", 81, 360, true),
      scalefinder::PianoKey("A#5", 82, 375, false),
      scalefinder::PianoKey("B5", 83, 390, true),
  };

  MyApp();
  void setup() override;
  void update() override;
  void draw() override;

 private:
  /** Holds all the chord symbols that have been entered */
  scalefinder::Engine engine_;
  /** The chord that the user wants to select scales from */
  scalefinder::ChordSymbol current_chord_;
  /** The scale currently displayed on the piano */
  scalefinder::Scale current_scale_;

  std::vector<int> keynums_to_highlight;
  int selected_chord_index_;
  int selected_scale_index_;
  bool is_seventh;
  std::chrono::time_point<std::chrono::system_clock> last_audio_play_time;
  cinder::audio::GenNodeRef mGen;    // Gen's generate audio signals
  cinder::audio::GainNodeRef mGain;  // Gain modifies the volume of the signal

  void DrawPiano();
  static void DrawKey(const scalefinder::PianoKey& key, bool is_highlighted);
  void DrawChordInput();
  void DrawChordList();
  void DrawScaleList();
  void DrawScaleText();
  void DrawPlaybackButton();
  // Copied from the Snake assignment.
  static void PrintText(const std::string& text, const cinder::Color& color,
                        const cinder::ivec2& size, const cinder::vec2& loc);
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
