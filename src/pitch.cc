//
// Created by Cale Wolf on 4/19/20.
//

#include "scalefinder/pitch.h"

#include <iostream>
#include <vector>

namespace scalefinder {

Pitch::Pitch(const std::string& pitch_str) {
  if (pitch_str.empty()) {
    throw std::out_of_range("Tried to create empty string");
  }

  std::string copy = pitch_str;

  // Initializes letter_ with the first letter of the string.
  std::string first_char = std::string(1, std::toupper(copy[0]));
  for (int i = 0; i < 7; ++i) { // TODO: Fix magic number
    if (kLetterNames[i] == first_char) {
      letter_ = i;
    }
  }

  // Initializes accidental_ and octave_.
  if (IsNumeric(copy.substr(1))) { // i.e. "C4"
    accidental_ = 2;
    octave_ = FindOctaveIndex(copy, 1);
  } else if (copy.substr(1, 1) == "n" && IsNumeric(copy.substr(2))) { // i.e. "Cn5"
    accidental_ = 2;
    octave_ = FindOctaveIndex(copy, 2);
  } else if (copy.substr(1, 2) == "bb" && IsNumeric(copy.substr(3))) { // i.e. "Cbb5"
    accidental_ = 0;
    octave_ = FindOctaveIndex(copy, 3);
  } else if (copy.substr(1, 2) == "##" && IsNumeric(copy.substr(3))) { // i.e. "C##5"
    accidental_ = 4;
    octave_ = FindOctaveIndex(copy, 3);
  } else if (copy.substr(1, 1) == "b" && IsNumeric(copy.substr(2))) { // i.e. "Cb5"
    accidental_ = 1;
    octave_ = FindOctaveIndex(copy, 2);
  } else if (copy.substr(1, 1) == "#" && IsNumeric(copy.substr(2))) { // i.e. "C#5"
    accidental_ = 3;
    octave_ = FindOctaveIndex(copy, 2);
  }

  if (accidental_ == -1 || letter_ == -1 || octave_ == -1) { // INVALID INPUT
    throw std::runtime_error("Invalid pitch string.");
  }

  pos_ = GetPos();

  //std::cout << letter_ << std::endl;
  //std::cout << accidental_ << std::endl;
  //std::cout << octave_ << std::endl;
}

Pitch::Pitch(int letter, int accidenal, int octave) {
  if (letter > 6 || letter < 0) {
    throw std::out_of_range("Letter number out of range");
  } else if (accidenal > 4 || accidenal < 0) {
    throw std::out_of_range("Accidental number out of range");
  } else if (octave > 10 || octave < 0) {
    throw std::out_of_range("Octave number out of range");
  }

  letter_ = letter;
  accidental_ = accidenal;
  octave_ = octave;

  pos_ = GetPos();
}

bool Pitch::IsNumeric(const std::string& value) {
  return value.find_first_not_of( "0123456789" ) == std::string::npos;
}

int Pitch::FindOctaveIndex(const std::string& copy, int pos) {
  for (int i = 0; i < 11; ++i) { // TODO: Replace magic number
    if (kOctaveNames[i] == copy.substr(pos)) {
      return i;
    }
  }
  return -1;
}

std::string Pitch::ToString() {
  return kLetterNames[letter_] + kAccidentalNames[accidental_] + kOctaveNames[octave_];
}

std::ostream& operator<<(std::ostream& os, Pitch& pitch) {
  os << pitch.ToString();
  return os;
}

int Pitch::GetPos() {
  // TODO: Why is this a problem?
  return (octave_ << 8) + (letter_ << 4) + accidental_;
}

bool Pitch::operator==(const Pitch& other) const {
  return pos_ == other.pos_;
}
bool Pitch::operator!=(const Pitch& other) const {
  return pos_ != other.pos_;
}
bool Pitch::operator<=(const Pitch& other) const {
  return pos_ <= other.pos_;
}
bool Pitch::operator>=(const Pitch& other) const {
  return pos_ >= other.pos_;
}
bool Pitch::operator<(const Pitch& other) const {
  return pos_ < other.pos_;
}
bool Pitch::operator>(const Pitch& other) const {
  return pos_ > other.pos_;
}

int Pitch::Keynum() {
  int pitch_intervals[7] = {0, 2, 4, 5, 7, 9, 11};
  int accidentals[5] = {-2, -1, 0, 1, 2};
  int midi_num = 12 * octave_ + pitch_intervals[letter_] + accidentals[accidental_];
  if (midi_num > 127 || midi_num < 0) {
    throw std::out_of_range("Midi keynum out of bounds");
  }
  return midi_num;
}

int Pitch::PitchClass() {
  return Keynum() % 12;
}

Pitch Pitch::FromKeynum(int keynum, std::string acci) {
  // TODO: Implement this.
  return Pitch("C3");
}

}  // namespace scalefinder