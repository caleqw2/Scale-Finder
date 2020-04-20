//
// Created by Cale Wolf on 4/19/20.
//

#include "scalefinder/scale.h"

#include <sstream>

namespace scalefinder {

Scale::Scale(Pitch tonic, ScaleType type) {
  if (scale_intervals.count(type) == 0) {
    throw std::runtime_error("Scale type not found!");
  }

  name_ = GetScaleName(tonic, scale_names.at(type));
  notes_ = DetermineNotes(tonic, scale_intervals.at(type));
}

std::string Scale::GetScaleName(Pitch& tonic, const std::string& type_name) {
  return tonic.ToString().substr(0, 1) + " " + type_name;
}

std::vector<Pitch> Scale::DetermineNotes(Pitch& tonic, const std::vector<std::string>& intervals) {
  std::vector<Pitch> notes;

  for (const std::string& interval_string : intervals) {
    Interval interval = Interval(interval_string);
    notes.push_back(interval.Transpose(tonic));
  }

  return notes;
}

std::string Scale::ToString() {
  std::stringstream output;
  output << name_ + " ";
  for (Pitch pitch : notes_) {
    output << pitch.ToString().substr(0, 1) + ", ";
  }
  return output.str();
}

}  // namespace scalefinder