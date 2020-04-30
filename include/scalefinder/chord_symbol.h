//
// Created by Cale Wolf on 4/22/20.
//

#ifndef FINALPROJECT_SCALEFINDER_CHORD_SYMBOL_H
#define FINALPROJECT_SCALEFINDER_CHORD_SYMBOL_H

#include "chord_quals.h"
#include "pitch.h"

#include "scale.h"
namespace scalefinder {

/**
 * Represents a single chord symbol from user entry.
 */
class ChordSymbol {
 public:
  ChordSymbol();

  /**
   * Constructor.
   * @param root1 The root Pitch of the chord. (C in Cmaj7)
   * @param qual The ChordQual quality of the chord. (kMajor in Cmaj7)
   * @param is_seventh Whether the chord is a seventh chord.
   * @param extensions Any supported extensions (like #11, b9, b13, etc.)
   * @param name The string name of the chord
   */
  ChordSymbol(Pitch root1, ChordQual qual, bool is_seventh,
              std::string extensions, std::string name);

  /**
   * Fills possible_scales_ by determining what ScaleTypes work with the chord.
   * This is the core logic of the program.
   */
  void PopulateScales();

  std::string GetName();

  std::string ToString();

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
