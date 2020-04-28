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
        throw std::runtime_error(kInvalidIntervalStr);
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

  // Important, I'm neglecting edge cases here.
  // For this app, I have control over where intervals are created so only
  // valid intervals are made (like m3, M3). To use this in the future,
  // I'll want to implement safeguards for invalid intervals.
}

std::string Interval::ToString() {
  std::string kSigns[] = {"-", "", ""};
  return kSigns[sign_ + 1] + kQualList[qual_] 
  + std::to_string(span_ + 1 + (xoct_ * 7));
}

std::ostream& operator<<(std::ostream& os, Interval& interval) {
  os << interval.ToString();
  return os;
}

Pitch Interval::Transpose(Pitch other) {
  /* Determines the new pitch's MIDI key number by adding the interval's
   * semitones to the old key number.
   */
  int new_keynum = other.Keynum() + GetSemitones();
  int new_acci = 0;

  /*
   * The new accidental is determined by adding the old accidental int
   * to a modifier determined by the interval's qual_, then raising/lowering
   * it by 1 for certain pitches.
   */
  
  if (IsPerfectType()) {
      new_acci = other.GetAccidental() + sign_ * kPerfectModifiers[qual_];

      // Edge cases.
      if (span_ == 4 && other.GetLetter() == 6) {
          new_acci += 1;
      } else if (span_ == 3 && other.GetLetter() == 3) {
          new_acci -= 1;
      }

  } else {
      new_acci = other.GetAccidental() + sign_ * kImperfectModifiers[qual_];
      
      // Raises the accidentals of certain letters for each imperfect interval

      // If transposing an E, B by a second, raise the accidental
      if (span_ == 1 && std::count(kEB, kEB
      + (sizeof(kEB) / sizeof(kEB[0])), other.GetLetter()) > 0) {
          new_acci += 1;
          
          // If transposing a D, E, A, B by a third, raise the accidental
      } else if (span_ == 2 && std::count(kDEAB, kDEAB
      + (sizeof(kDEAB) / sizeof(kDEAB[0])), other.GetLetter()) > 0) {
          new_acci += 1;
          
          // If transposing a D, E, G, A, B by a seventh, raise accidental
      } else if (span_ == 6 && std::count(kDEGAB, kDEGAB
      + (sizeof(kDEGAB) / sizeof(kDEGAB[0])), other.GetLetter()) > 0) {
          new_acci += 1;
          
          // If transposing an E, A, B by a sixth, raise accidental
      } else if (span_ == 5 && std::count(kEAB, kEAB
      + (sizeof(kEAB) / sizeof(kEAB[0])), other.GetLetter()) > 0) {
          new_acci += 1;
      }
  }

  const int kValidAccis[] = {0, 1, 2, 3, 4};

  if (std::count(kValidAccis, kValidAccis + 
  (sizeof(kValidAccis) / sizeof(kValidAccis[0])), new_acci) == 0) {
      throw std::runtime_error(kTranspositionFailed);
  }

  return Pitch::FromKeynum(new_keynum, kValidAccisStrs[new_acci]);
}

int Interval::GetSemitones() {
    if (IsPerfectType()) {
        return sign_ * (kSemitoneList[span_] + kPerfectQualsList[qual_]
        + (kNotesInOctave * xoct_));
    } else {
        return sign_ * (kSemitoneList[span_] + kImperfectQualsList[qual_]
        + (kNotesInOctave * xoct_));
    }
}

bool Interval::IsPerfectType() {
    return std::count(kPerfectSpans, kPerfectSpans +
    (sizeof(kPerfectSpans) / sizeof(kPerfectSpans[0])), span_) == 1;
}

int Interval::FindQualIndex(const std::string& qual_string) {
  for (int i = 0; i < kNumQuals; ++i) {
    if (kQualList[i] == qual_string) {
      return i;
    }
  }
  return -1;
}

}  // namespace scalefinder