//
// Created by Cale Wolf on 4/19/20.
//

#ifndef FINALPROJECT_SCALEFINDER_INTERVAL_H
#define FINALPROJECT_SCALEFINDER_INTERVAL_H

#include <string>
#include "pitch.h"

namespace scalefinder {

const std::string kQualList[] = {"ooooo", "oooo", "ooo", "oo", "o", "m", "P", "M", "+", "++", "+++", "++++", "+++++"};
const std::string kValidAccisStrs[] = {"bb", "b", "None", "#", "##"};

const std::string kInvalidIntervalStr = "Invalid interval string!";
const std::string kTranspositionFailed = "Transposition invalid because a pitch couldn't be created with that accidental.";

const int kInvalid = 100;
const int kPerfectModifiers[] = {-5, -4, -3, -2, -1, kInvalid, 0, kInvalid, 1, 2, 3, 4, 5};
const int kImperfectModifiers[] = {-6, -5, -4, -3, -2, -1, kInvalid, 0, 1, 2, 3, 4, 5};
const int kEB[] = {2, 6};
const int kDEAB[] = {1, 2, 5, 6};
const int kDEGAB[] = {1, 2, 4, 5, 6};
const int kEAB[] = {2, 5, 6};
const int kSemitoneList[] = {0, 2, 4, 5, 7, 9, 11, 12};
const int kPerfectQualsList[] = {-5, -4, -3, -2, -1, kInvalid, 0, kInvalid, 1, 2, 3, 4, 5};
const int kImperfectQualsList[] = {-6, -5, -4, -3, -2, -1, kInvalid, 0, 1, 2, 3, 4, 5};
const int kPerfectSpans[] = {0, 3, 4, 7};

const int kNotesInOctave = 12;
const int kNumQuals = 13;

class Interval {
 public:
  // Constructs an interval from a string (i.e. Interval("++5") )
  explicit Interval(const std::string& str);

  // Print operator
  friend std::ostream& operator<<(std::ostream& os, Interval& interval);

  // Converts to a string representation
  std::string ToString();

  // Transposes a pitch by the current interval.
  Pitch Transpose(Pitch bottom);

 private:
  int span_ = -1;
  int qual_ = -1;
  int xoct_ = -1;
  int sign_ = 1;

  static int FindQualIndex(const std::string& qual_string);
  int GetSemitones();
  bool IsPerfectType();
};

}  // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_INTERVAL_H
