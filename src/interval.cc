//
// Created by Cale Wolf on 4/19/20.
//

#include "scalefinder/interval.h"

#include <iostream>

namespace scalefinder {

Interval::Interval(const std::string& str) {
  std::string string = str;

  if (string.substr(0, 1) == "-") {
    sign_ = -1;
    string = string.substr(1);
  }

  for (size_t i = 0; i < string.length(); ++i) {
    if (Pitch::IsNumeric(string.substr(i))) {
      if (FindQualIndex(string.substr(0, i)) == -1) {
        throw std::runtime_error("Invalid interval string!");
      }

      qual_ = FindQualIndex(string.substr(0, i));
      span_ = std::stoi(string.substr(i)) - 1;
      xoct_ = span_ / 7;

      if (span_ % 7 == 0 && span_ != 0) {
        xoct_ -= 1;
        span_ = 7;
      } else if (span_ > 7) { // Simplifies compound intervals
        span_ %= 7;
      }
      break;
    }
  }

  // TODO: Important, I'm neglecting edge cases here.
}

std::string Interval::ToString() {
  std::string signs[] = {"-", "", ""};
  return signs[sign_ + 1] + kQualList[qual_] + std::to_string(span_ + 1 + (xoct_ * 7));
}

std::ostream& operator<<(std::ostream& os, Interval& interval) {
  os << interval.ToString();
  return os;
}

Pitch Interval::Transpose(Pitch& other) {
  /* Determines the new pitch's MIDI key number by adding the interval's
   * semitones to the old key number.
   */
  int new_keynum = other.Keynum() + GetSemitones();

  int new_acci = 0;

  const int kInvalid = 100;
  const int perfect_modifiers[] = {-5, -4, -3, -2, -1, kInvalid, 0, kInvalid, 1, 2, 3, 4, 5};
  const int imperfect_modifiers[] = {-6, -5, -4, -3, -2, -1, kInvalid, 0, 1, 2, 3, 4, 5};
  const int const1[] = {2, 6};
  const int const2[] = {1, 2, 5, 6};
  const int const3[] = {1, 2, 4, 5, 6};
  const int const4[] = {2, 5, 6};
  const int const5[] = {0, 1, 2, 3, 4};

  if (IsPerfectType()) {
      new_acci = other.GetAccidental() + sign_ * perfect_modifiers[qual_];

      // Edge cases.
      if (span_ == 4 && other.GetLetter() == 6) {
          new_acci += 1;
      } else if (span_ == 3 && other.GetLetter() == 3) {
          new_acci -= 1;
      }

  } else {
      new_acci = other.GetAccidental() + sign_ * imperfect_modifiers[qual_];

      // Whole lot of edge cases.
      if (span_ == 1 && std::count(const1, const1 + (sizeof(const1) / sizeof(const1[0])), other.GetLetter()) > 0) {
          new_acci += 1;
      } else if (span_ == 2 && std::count(const2, const2 + (sizeof(const2) / sizeof(const2[0])), other.GetLetter()) > 0) {
          new_acci += 1;
      } else if (span_ == 6 && std::count(const3, const3 + (sizeof(const3) / sizeof(const3[0])), other.GetLetter()) > 0) {
          new_acci -= 1;
      } else if (span_ == 5 && std::count(const4, const4 + (sizeof(const4) / sizeof(const4[0])), other.GetLetter()) > 0) {
          new_acci -= 1;
      }
  }

  if (std::count(const5, const5 + (sizeof(const5) / sizeof(const5[0])), new_acci) == 0) {
      throw std::runtime_error("Transposition invalid because a pitch couldn't be created with that accidental.");
  }

  std::string possible_accis[] = {"bb", "b", "None", "#", "##"};
  return Pitch::FromKeynum(new_keynum, possible_accis[new_acci]);
}

int Interval::GetSemitones() {
    const int semitone_list[] = {0, 2, 4, 5, 7, 9, 11, 12};
    const int kInvalid = 100;
    const int perfect_quals_list[] = {-5, -4, -3, -2, -1, kInvalid, 0, kInvalid, 1, 2, 3, 4, 5};
    const int imperfect_quals_list[] = {-6, -5, -4, -3, -2, -1, kInvalid, 0, 1, 2, 3, 4, 5};

    if (IsPerfectType()) {
        return sign_ * (semitone_list[span_] + perfect_quals_list[qual_] + (12 * xoct_));
    } else {
        return sign_ * (semitone_list[span_] + imperfect_quals_list[qual_] + (12 * xoct_));
    }
}

bool Interval::IsPerfectType() {
    int perfect_list[] = {0, 3, 4, 7};
    return std::count(perfect_list, perfect_list + (sizeof(perfect_list) / sizeof(perfect_list[0])), span_) == 1;
}

int Interval::FindQualIndex(const std::string& qual_string) {
  for (int i = 0; i < 13; ++i) { // TODO: Replace magic number
    if (kQualList[i] == qual_string) {
      return i;
    }
  }
  return -1;
}

}  // namespace scalefinder