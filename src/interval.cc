//
// Created by Cale Wolf on 4/19/20.
//

#include "scalefinder/interval.h"

namespace scalefinder {

Interval::Interval(const std::string& str) {
  std::string string = str;

  if (string.substr(0, 1) == "-") {
    sign_ = -1;
    string = string.substr(1);
  }

  for (size_t i = 0; i < string.length(); ++i) {
    if
  }
}

}  // namespace scalefinder