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
      } else if (span_ > 7) {
        span_ %= 7;
      }
      break;
    }
  }

  // TODO: Important, I'm neglecting edge cases here.
}

int Interval::FindQualIndex(const std::string& qual_string) {
  for (int i = 0; i < 13; ++i) { // TODO: Replace magic number
    if (kQualList[i] == qual_string) {
      return i;
    }
  }
  return -1;
}

std::string Interval::ToString() {
  std::string signs[] = {"-", "", ""};
  return signs[sign_ + 1] + kQualList[qual_] + std::to_string(span_ + 1 + (xoct_ * 7));
}

std::ostream& operator<<(std::ostream& os, Interval& interval) {
  os << interval.ToString();
  return os;
}

}  // namespace scalefinder