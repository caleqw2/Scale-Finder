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

MyApp::MyApp() {

}

void MyApp::setup() {
  ImGui::initialize();
}

void MyApp::update() {
  engine_ = Engine("DbM7 F7b9 BbM7#11");
  current_chord_ = engine_.GetChords()[0];
  current_scale_ = current_chord_.GetScales()[0];

  for (Pitch pitch : current_scale_.GetNotes()) {
    keynums_to_highlight.push_back(pitch.Keynum());
  }
}

void MyApp::draw() {
  cinder::gl::clear();
  ImGui::Text("Hello, world!");
  DrawPiano();

}

void MyApp::keyDown(KeyEvent event) { }



void MyApp::DrawPiano() {
  //keynums_to_highlight = {60, 62, 64};

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

}  // namespace myapp
