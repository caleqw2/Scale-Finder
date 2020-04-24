// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <scalefinder/engine.h>
#include <scalefinder/piano_key.h>

namespace myapp {

const int kWhiteKeyHeight = 150;
const int kWhiteKeyWidth = 30;
const int kBlackKeyHeight = 100;
const int kBlackKeyWidth = 20;

const int pianox = 200;
const int pianoy = 600;

class MyApp : public cinder::app::App {
 public:
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
  void keyDown(cinder::app::KeyEvent) override;

 private:
  scalefinder::Engine engine_;
  scalefinder::ChordSymbol current_chord_;
  scalefinder::Scale current_scale_;
  std::vector<int> keynums_to_highlight;
  static void DrawKey(const scalefinder::PianoKey& key, bool is_highlighted);
  void DrawPiano();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
