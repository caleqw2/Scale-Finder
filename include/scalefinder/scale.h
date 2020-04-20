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
  const std::map<ScaleType, std::vector<std::string>> scale_intervals = {
      {ScaleType::kMajor, {"P1", "M2", "M3", "P4", "P5", "M6", "M7", "P8"}}
  };
  const std::map<ScaleType, std::string> scale_names = {
      {ScaleType::kMajor, "Major"}
  };

 public:
  Scale(Pitch tonic, ScaleType type);
  std::string ToString();
  friend std::ostream& operator<<(std::ostream& os, Scale& scale);
 private:
  std::string name_; // e.g. (B Major or C# Dorian)
  std::vector<Pitch> notes_; // All the Pitches in the scale.
  static std::string GetScaleName(Pitch& tonic, const std::string& type_name);
  static std::vector<Pitch> DetermineNotes(Pitch& tonic,
      const std::vector<std::string>& intervals);
};

}  // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_SCALE_H
