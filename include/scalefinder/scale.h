//
// Created by Cale Wolf on 4/19/20.
//

#ifndef FINALPROJECT_SCALEFINDER_SCALE_H
#define FINALPROJECT_SCALEFINDER_SCALE_H

#include <map>

#include "pitch.h"
#include "scaletype.h"

namespace scalefinder {

class Scale {
 public:
  const std::map<ScaleType, std::vector<std::string>> scale_intervals = {
      {ScaleType::kMajor, {"m2, m3, m3"}}
  };
  const std::map<ScaleType, std::string> scale_names = {
      {ScaleType::kMajor, "Major"}
  };

  Scale(Pitch tonic, ScaleType type);
 private:
  std::vector<Pitch> notes_;
  std::string name_;
};

}  // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_SCALE_H
