// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "scale_finder_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/gl/wrapper.h>
#include <gflags/gflags.h>

#include "CinderImGui.h"

namespace myapp {

using cinder::app::KeyEvent;
using cinder::Rectf;
using scalefinder::Engine;
using scalefinder::Pitch;
using scalefinder::ChordSymbol;
using scalefinder::ChordQual;

MyApp::MyApp() {

}

void MyApp::setup() {
  ImGui::initialize();
  is_seventh = false;
  engine_ = Engine("DbM7 F7b9 BbM7#11");
  /*
  for (int i = 0; i < engine_.GetChords().size(); ++i) {
    std::cout << engine_.GetChords()[i].GetName() << std::endl;
  } */
}

void MyApp::update() {
  current_chord_ = engine_.GetChords()[selected_chord_index_];
  current_scale_ = current_chord_.GetScales()[0];

  keynums_to_highlight.clear();
  for (Pitch pitch : current_scale_.GetNotes()) {
    keynums_to_highlight.push_back(pitch.Keynum());
  }
}

void MyApp::draw() {
  cinder::gl::clear();

  DrawChordInput();

  DrawChordList();

  // TODO: Draw a Combo to select potential scales from chords

  // TODO: Draw text displaying the notes in the current scale

  // TODO: Draw a help box for understanding chord input

  // TODO:

  // Draws the piano.
  DrawPiano();
}

void MyApp::keyDown(KeyEvent event) { }



void MyApp::DrawPiano() {
  // Draws white keys first so black keys can be on top.
  for (const scalefinder::PianoKey& key : kPianoKeys) {
    bool is_highlighted = std::count(keynums_to_highlight.begin(), keynums_to_highlight.end(), key.GetKeynum()) > 0;
    if (key.IsWhite()) {
      DrawKey(key, is_highlighted);
    }
  }

  for (const scalefinder::PianoKey& key : kPianoKeys) {
    bool is_highlighted = std::count(keynums_to_highlight.begin(), keynums_to_highlight.end(), key.GetKeynum()) > 0;
    if (!key.IsWhite()) {
      DrawKey(key, is_highlighted);
    }
  }
}

void MyApp::DrawKey(const scalefinder::PianoKey& key, bool is_highlighted) {
  Rectf dimensions;
  cinder::Color key_color;
  if (key.IsWhite()) {
    dimensions = Rectf(pianox + key.GetXloc(), pianoy,pianox + key.GetXloc() + kWhiteKeyWidth, pianoy + kWhiteKeyHeight);
    key_color = cinder::Color(1, 1, 1);
  } else {
    dimensions = Rectf(pianox + key.GetXloc(), pianoy, pianox + key.GetXloc() + kBlackKeyWidth, pianoy + kBlackKeyHeight);
    key_color = cinder::Color(0, 0, 0);
  }

  if (is_highlighted) {
    key_color = cinder::Color(0, 0, 1);
  }

  cinder::gl::color(key_color); // Draws the key
  cinder::gl::drawSolidRect(dimensions);
  cinder::gl::color(0, 0 ,0); // Draws a border
  cinder::gl::drawStrokedRect(dimensions);
}

void MyApp::DrawChordInput() {
  // Gets the chord's root from a text box
  static char root_str[128] = "";
  ImGui::InputText("Tonic", root_str, IM_ARRAYSIZE(root_str));

  // Gets the chord's quality from a dropdown menu
  const char* quals[] = { "M", "m", "o", "+", "0", "dom" };
  static int item_current = 0;
  ImGui::Combo("Quality", &item_current, quals, IM_ARRAYSIZE(quals));
  std::string qual_str = quals[item_current];
  if (qual_str == "dom") {
    qual_str = "";
  }

  // Gets whether the chord is a 7th from radio buttons
  if (ImGui::RadioButton("7", is_seventh)) { is_seventh = true; }
  if (ImGui::RadioButton("No 7", !is_seventh)) { is_seventh = false; }
  std::string seventh_str;
  if (is_seventh) {
    seventh_str = "7";
  }

  // Gets any extensions from a dropdown menu
  const char* exts[] = { "none", "b9", "#9b13", "alt", "#11" };
  static int item_current_1 = 0;
  ImGui::Combo("Extensions", &item_current_1, exts, IM_ARRAYSIZE(exts));
  std::string ext_str = exts[item_current_1];
  if (ext_str == "none") {
    ext_str = "";
  }

  // Tries to create the chord if valid input. Then adds to engine.
  if (ImGui::Button("Create Chord")) {
    try {
      Pitch p = Pitch(std::string(root_str) + "4");
      std::string chord_name = std::string(root_str) + qual_str + seventh_str + ext_str;
      ChordSymbol new_chord = ChordSymbol(p, quals_map[quals[item_current]], is_seventh, ext_str, chord_name);
      engine_.AddChord(new_chord);

      std::cout << "Chord made!" << std::endl;
      std::cout << new_chord.GetName() << std::endl;
    } catch (std::runtime_error&) {
      std::cout << "Bad chord." << std::endl;
    }
  }
}

void MyApp::DrawChordList() {
  std::string chords_str_with_zeros;
  for (size_t i = 0; i < engine_.GetChords().size(); ++i) {
    chords_str_with_zeros += engine_.GetChords()[i].GetName() + '\0';
  }
  const char* c = chords_str_with_zeros.c_str();
  ImGui::Combo("Chords Added", &selected_chord_index_, c);
}

}  // namespace myapp
