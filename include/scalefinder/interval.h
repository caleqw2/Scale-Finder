//
// Created by Cale Wolf on 4/19/20.
//

#ifndef FINALPROJECT_SCALEFINDER_INTERVAL_H
#define FINALPROJECT_SCALEFINDER_INTERVAL_H

#include <string>
#include "pitch.h"

namespace scalefinder {

const std::string kQualList[] = {"ooooo", "oooo", "ooo", "oo", "o", "m", "P", "M", "+", "++", "+++", "++++", "+++++"};

class Interval {
 public:
  // Constructs an interval from a string (i.e. Interval("++5") )
  explicit Interval(const std::string& str);

  // Print operator
  friend std::ostream& operator<<(std::ostream& os, Interval& interval);

  // Converts to a string representation
  std::string ToString();

  // Transposes a pitch by the current interval.
  Pitch Transpose(Pitch& bottom);

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
