//
// Created by Cale Wolf on 4/22/20.
//

#ifndef FINALPROJECT_SCALEFINDER_ENGINE_H
#define FINALPROJECT_SCALEFINDER_ENGINE_H

#include <vector>

#include "chord_symbol.h"
namespace scalefinder {

class Engine {
 public:
  // Takes in an un-formatted string of chords separated by spaces e.g. [Cmaj7 F6 Bbm9(#11)]
  // Splits it into a vector of strings.
  // Takes each single chord string and generates a ChordSymbol from it using GetChordFromString()
  // The ChordSymbol will populate it's scales list upon construction.
  Engine(std::string raw_input);
  ChordSymbol GetChordFromString(std::string chord_str);

  // Prints all the chords with all their scales for testing purposes.
  std::string PrintAllChordsAndScales();
 private:
  std::vector<ChordSymbol> chords_;
};

} // namespace scalefinder

#endif  // FINALPROJECT_ENGINE_H
