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
              std::string extensions, std::string name);
  // Fills possible_scales by determining what ScaleTypes work for that scale.
  // Also handles chord extensions.
  void PopulateScales();
  std::string GetName();
  std::vector<Scale> GetScales();
 private:
  Pitch root_;
  scalefinder::ChordQual qual_;
  bool is_seventh_;
  std::string extensions_;
  std::string name_;
  std::vector<scalefinder::Scale> possible_scales_;
  void AddScale(ScaleType qual);
};

} // namespace scalefinder

#endif  // FINALPROJECT_CHORD_SYMBOL_H
