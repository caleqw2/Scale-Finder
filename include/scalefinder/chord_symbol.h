//
// Created by Cale Wolf on 4/22/20.
//

#ifndef FINALPROJECT_SCALEFINDER_CHORD_SYMBOL_H
#define FINALPROJECT_SCALEFINDER_CHORD_SYMBOL_H

#include "chord_quals.h"
#include "pitch.h"

#include "scale.h"
namespace scalefinder {

class ChordSymbol {
 public:
  ChordSymbol(Pitch root1, ChordQual qual, bool is_seventh,
              std::vector<std::string> extensions);
  // Fills possible_scales by determining what ScaleTypes work for that scale.
  // Also handles chord extensions.
  static void PopulateScales();
 private:
  Pitch root_;
  scalefinder::ChordQual qual_;
  bool is_seventh_;
  std::vector<std::string> extensions_;
  std::vector<scalefinder::Scale> possible_scales;
};

} // namespace scalefinder

#endif  // FINALPROJECT_CHORD_SYMBOL_H
