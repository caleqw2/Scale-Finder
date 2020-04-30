//
// Created by Cale Wolf on 4/19/20.
//

#include "scalefinder/pitch.h"

#include <cmath>
#include <iostream>
#include <vector>

namespace scalefinder {

Pitch::Pitch() = default;

Pitch::Pitch(const std::string& pitch_str) {
  if (pitch_str.empty()) {
    throw std::runtime_error(kEmptyPitchStringMessage);
  }

  // Initializes letter_ with the first letter of the string.
  std::string first_char = std::string(1, std::toupper(pitch_str[0]));
  for (int i = 0; i < kNumPitchLetters; ++i) {
    if (kLetterNames[i] == first_char) {
      letter_ = i;
    }
  }

  // Initializes accidental_ and octave_.
  if (IsNumeric(pitch_str.substr(1))) {  // i.e. "C4"
    accidental_ = 2;
    octave_ = FindOctaveIndex(pitch_str, 1);
  } else if (pitch_str.substr(1, 1) == "n" &&
             IsNumeric(pitch_str.substr(2))) {  // i.e. "Cn5"
    accidental_ = 2;
    octave_ = FindOctaveIndex(pitch_str, 2);
  } else if (pitch_str.substr(1, 2) == "bb" &&
             IsNumeric(pitch_str.substr(3))) {  // i.e. "Cbb5"
    accidental_ = 0;
    octave_ = FindOctaveIndex(pitch_str, 3);
  } else if (pitch_str.substr(1, 2) == "##" &&
             IsNumeric(pitch_str.substr(3))) {  // i.e. "C##5"
    accidental_ = 4;
    octave_ = FindOctaveIndex(pitch_str, 3);
  } else if (pitch_str.substr(1, 1) == "b" &&
             IsNumeric(pitch_str.substr(2))) {  // i.e. "Cb5"
    accidental_ = 1;
    octave_ = FindOctaveIndex(pitch_str, 2);
  } else if (pitch_str.substr(1, 1) == "#" &&
             IsNumeric(pitch_str.substr(2))) {  // i.e. "C#5"
    accidental_ = 3;
    octave_ = FindOctaveIndex(pitch_str, 2);
  }

  if (accidental_ == -1 || letter_ == -1 || octave_ == -1) {  // INVALID INPUT
    throw std::runtime_error(kInvalidPitchString);
  }

  // Why is this giving me a warning?
  pos_ = (octave_ << 8) + (letter_ << 4) + accidental_;
}

bool Pitch::IsNumeric(const std::string& value) {
  return value.find_first_not_of("0123456789") == std::string::npos;
}

int Pitch::FindOctaveIndex(const std::string& copy, int pos) {
  for (int i = 0; i < kNumOctaves; ++i) {
    if (kOctaveNames[i] == copy.substr(pos)) {
      return i;
    }
  }
  return -1;
}

std::string Pitch::ToString() {
  return kLetterNames[letter_] + kAccidentalNames[accidental_] +
         kOctaveNames[octave_];
}

std::ostream& operator<<(std::ostream& os, Pitch& pitch) {
  os << pitch.ToString();
  return os;
}

bool Pitch::operator==(const Pitch& other) const { return pos_ == other.pos_; }

bool Pitch::operator!=(const Pitch& other) const { return pos_ != other.pos_; }

int Pitch::Keynum() {
  int pitch_intervals[7] = {0, 2, 4, 5, 7, 9, 11};
  int accidentals[5] = {-2, -1, 0, 1, 2};
  int midi_num =
      12 * octave_ + pitch_intervals[letter_] + accidentals[accidental_];
  if (midi_num > 127 || midi_num < 0) {
    throw std::out_of_range(kKeynumOutOfRange);
  }
  return midi_num;
}

Pitch Pitch::FromKeynum(int keynum, const std::string& acci) {
  if (keynum > 127 || keynum < 0) {
    throw std::runtime_error(kInvalidKeynum);
  }

  /*
   * Creates a pitch from a keynum by making a pitch string and using the
   * string constructor.
   */

  int octave_number = keynum / 12;
  int pc = keynum % 12;

  std::string pitch_name;

  if (acci == "None") {
    pitch_name = kNoAcciPitches[pc] + kOctaveNames[octave_number];

  } else if (acci == "#" || acci == "s") {
    if (pc == 0) {
      octave_number -= 1;
    }
    pitch_name = kSharpPitches[pc] + kOctaveNames[octave_number];

  } else if (acci == "b" || acci == "f") {
    if (pc == 11) {
      octave_number += 1;
    }
    pitch_name = kFlatPitches[pc] + kOctaveNames[octave_number];

  } else if (acci == "##" || acci == "ss") {
    if (pc == 1) {
      octave_number -= 1;
    }
    pitch_name = kDoubleSharpPitches[pc] + kOctaveNames[octave_number];

  } else if (acci == "bb" || acci == "ff") {
    if (pc == 10) {
      octave_number += 1;
    }
    pitch_name = kDoubleFlatPitches[pc] + kOctaveNames[octave_number];

  } else {
    throw std::runtime_error(kBadAcciFormat);
  }

  if (pitch_name[0] == 'x') {
    throw std::runtime_error(kInvalidAcci);
  }

  // Uses the pitch constructor with the newly generated pitch string.
  return Pitch(pitch_name);
}

int Pitch::GetAccidental() { return accidental_; }

int Pitch::GetLetter() { return letter_; }

std::string Pitch::GetNote() {
  return kLetterNames[letter_] + kAccidentalNames[accidental_];
}

double Pitch::Hertz() {
  return 440.0 * pow(2, ((Keynum() - 69) / 12.0));
}

}  // namespace scalefinder