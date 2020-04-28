//
// Created by Cale Wolf on 4/19/20.
//

#include "scalefinder/scale.h"

#include <sstream>

namespace scalefinder {

Scale::Scale() = default;

Scale::Scale(Pitch tonic, ScaleType type) {
  assert(scale_intervals.count(type) != 0);
  name_ = GetScaleName(tonic, scale_names.at(type));
  notes_ = DetermineNotes(tonic, scale_intervals.at(type));
}

std::string Scale::GetScaleName(Pitch& tonic, const std::string& type_name) {
  return tonic.GetNote() + " " + type_name;
}

std::vector<Pitch> Scale::DetermineNotes(Pitch& tonic,
    const std::vector<std::string>& intervals) {
  std::vector<Pitch> notes;

  for (const std::string& interval_string : intervals) {
    Interval interval = Interval(interval_string);
    notes.push_back(interval.Transpose(tonic));
  }

  return notes;
}

std::string Scale::ToString() {
  std::stringstream output;
  output << name_ + ": [";
  for (Pitch pitch : notes_) {
    output << pitch.GetNote() + ", ";
  }
  std::string output_str = output.str();
  output_str.pop_back();
  output_str.pop_back();
  output_str += "]";

  return output_str;
}

std::ostream& operator<<(std::ostream& os, Scale& scale) {
  os << scale.ToString();
  return os;
}

const std::vector<Pitch>& Scale::GetNotes() const { return notes_; }

}  // namespace scalefinder