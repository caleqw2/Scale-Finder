//
// Created by Cale Wolf on 4/19/20.
//

#ifndef FINALPROJECT_SCALEFINDER_SCALE_H
#define FINALPROJECT_SCALEFINDER_SCALE_H

#include <map>

#include "pitch.h"
#include "scaletype.h"
#include "interval.h"

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
  std::string ToString();

 private:
  std::string name_;
  std::vector<Pitch> notes_;
  static std::string GetScaleName(Pitch& tonic, const std::string& type_name);
  static std::vector<Pitch> DetermineNotes(Pitch& tonic, const std::vector<std::string>& intervals);
};

}  // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_SCALE_H
