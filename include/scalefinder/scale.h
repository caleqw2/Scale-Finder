//
// Created by Cale Wolf on 4/19/20.
//

#ifndef FINALPROJECT_SCALEFINDER_SCALE_H
#define FINALPROJECT_SCALEFINDER_SCALE_H

#include <map>

#include "interval.h"
#include "pitch.h"
#include "scaletype.h"

namespace scalefinder {

const std::map<ScaleType, std::vector<std::string>> scale_intervals = {
    {ScaleType::kIonian, {"P1", "M2", "M3", "P4", "P5", "M6", "M7", "P8"}},
    {ScaleType::kDorian, {"P1", "M2", "m3", "P4", "P5", "M6", "m7", "P8"}},
    {ScaleType::kLydianMajor, {"P1", "M2", "M3", "+4", "P5", "M6", "M7", "P8"}},
    {ScaleType::kAeolian, {"P1", "M2", "m3", "P4", "P5", "m6", "m7", "P8"}},
    {ScaleType::kLydianDominant, {"P1", "M2", "M3", "+4", "P5", "M6", "m7", "P8"}},
    {ScaleType::kAltered, {"P1", "m2", "m3", "M3", "+4", "+5", "m7", "P8"}},
    {ScaleType::kLocrian, {"P1", "m2", "m3", "P4", "o5", "m6", "m7", "P8"}},
    {ScaleType::kSuperLocrian, {"P1", "M2", "m3", "P4", "o5", "m6", "m7", "P8"}},
    {ScaleType::kHalfWholeDim, {"P1", "m2", "m3", "M3", "+4", "P5", "M6", "m7", "P8"}},
    {ScaleType::kWholeHalfDim, {"P1", "M2", "m3", "P4", "o5", "m6", "M6", "M7", "P8"}},
    {ScaleType::kWholeTone, {"P1", "M2", "M3", "+4", "+5", "+6", "P8"}},
    {ScaleType::kMelodicMinor, {"P1", "M2", "m3", "P4", "P5", "M6", "M7", "P8"}},
    {ScaleType::kMixolydian, {"P1", "M2", "M3", "P4", "P5", "M6", "m7", "P8"}}
};

const std::map<ScaleType, std::string> scale_names = {
    {ScaleType::kIonian, "Major"},
    {ScaleType::kDorian, "Dorian Minor"},
    {ScaleType::kLydianMajor, "Lydian Major"},
    {ScaleType::kAeolian, "Minor"},
    {ScaleType::kLydianDominant, "Lydian Dominant"},
    {ScaleType::kAltered, "Altered"},
    {ScaleType::kLocrian, "Locrian"},
    {ScaleType::kSuperLocrian, "Super Locrian"},
    {ScaleType::kHalfWholeDim, "Half-Whole Diminished"},
    {ScaleType::kWholeHalfDim, "Whole-Half Diminished"},
    {ScaleType::kWholeTone, "Whole Tone"},
    {ScaleType::kMelodicMinor, "Melodic Minor"},
    {ScaleType::kMixolydian, "Mixolydian"}
};

/**
 * Represents a scale, which is a collection of pitches.
 */
class Scale {
 public:
  Scale();
  /**
   * Constructs a scale.
   * @param tonic The root note of the scale. (like C in a Cmaj scale.)
   * @param type The quality of the scale, like Major in a Cmaj scale.
   */
  Scale(Pitch tonic, ScaleType type);
  std::string ToString();
  friend std::ostream& operator<<(std::ostream& os, Scale& scale);
  const std::vector<Pitch>& GetNotes() const;
  std::string GetName();
 private:
  std::string name_; // e.g. (B Major or C# Dorian)
  std::vector<Pitch> notes_;

  // All the Pitches in the scale.
  static std::string GetScaleName(Pitch& tonic, const std::string& type_name);

  /**
   * Populates the scale with pitches.
   * @param tonic The root note of the scale
   * @param intervals All the intervals of the rest of the scale degrees
   * @return A vector of pitches to go in notes_.
   */
  static std::vector<Pitch> DetermineNotes(
      Pitch& tonic, const std::vector<std::string>& intervals);

};

}  // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_SCALE_H
