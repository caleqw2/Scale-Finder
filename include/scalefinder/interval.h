//
// Created by Cale Wolf on 4/19/20.
//

#ifndef FINALPROJECT_SCALEFINDER_INTERVAL_H
#define FINALPROJECT_SCALEFINDER_INTERVAL_H

#include <string>
#include "pitch.h"

namespace scalefinder {

class Interval {
 public:
  // Constructs an interval from a string (i.e. Interval("++5") )
  explicit Interval(std::string str);

  // Constructs an interval from four ints
  Interval(int span, int qual, int xoct, int sign);
  // Constructs an interval from two pitches
  Interval(Pitch p1, Pitch p2);

  // Print operator
  friend std::ostream& operator<<(std::ostream& os, Interval& interval);

  // Equality operators
  bool operator==(const Interval& other) const;
  bool operator!=(const Interval& other) const;
  bool operator<=(const Interval& other) const;
  bool operator>=(const Interval& other) const;
  bool operator<(const Interval& other) const;
  bool operator>(const Interval& other) const;

  // Converts to a string representation
  std::string ToString();
  std::string FullName();
  std::string SpanName();
  std::string quality_name();
  bool matches(const Interval& other);
  int lines_and_spaces();

  // Not here yet: is_unison, is_second, etc...
  // Not here: is_dimisned, is_major, is_augmented, etc...

 private:

  // Helper function used to calculate pos_. Used in constructor.
  int get_pos();
};

}  // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_INTERVAL_H
