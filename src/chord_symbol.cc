//
// Created by Cale Wolf on 4/22/20.
//

#include "scalefinder/chord_symbol.h"

#include <utility>

namespace scalefinder {

ChordSymbol::ChordSymbol(Pitch root, ChordQual qual, bool is_seventh, std::string extensions, std::string name)
    : root_(root), qual_(qual), is_seventh_(is_seventh), extensions_(std::move(extensions)), name_(std::move(name)) {
  PopulateScales();
}

std::string ChordSymbol::GetName() { return name_; }

std::vector<Scale> ChordSymbol::GetScales() { return possible_scales_; }

void ChordSymbol::PopulateScales() {
  // TODO: Add some more details for what scales go with what chords.
  switch(qual_) {
    case ChordQual::kMajor:
      if (extensions_ == "#11") {
        AddScale(ScaleType::kLydianMajor);
      } else {
        AddScale(ScaleType::kIonian);
      }
      break;
    case ChordQual::kMinor:
      AddScale(ScaleType::kDorian);
      AddScale(ScaleType::kMelodicMinor);
      AddScale(ScaleType::kAeolian);
      break;
    case ChordQual::kAugmented:
      AddScale(ScaleType::kWholeTone);
      break;
    case ChordQual::kDiminished:
      AddScale(ScaleType::kWholeHalfDim);
      break;
    case ChordQual::kHalfDiminished:
      AddScale(ScaleType::kLocrian);
      AddScale(ScaleType::kSuperLocrian);
      break;
    case ChordQual::kDominant:
      if (extensions_ == "#11") {
        AddScale(ScaleType::kLydianDominant);
      } else if (extensions_ == "b9") {
        AddScale(ScaleType::kHalfWholeDim);
      } else if (extensions_ == "alt" || extensions_ == "#9b13") {
        AddScale(ScaleType::kAltered);
      } else {
        AddScale(ScaleType::kMixolydian);
      }
      break;
  }
}

void ChordSymbol::AddScale(ScaleType qual) {
  possible_scales_.emplace_back(root_, qual);
}

ChordSymbol::ChordSymbol() = default;

} // namespace scalefinder