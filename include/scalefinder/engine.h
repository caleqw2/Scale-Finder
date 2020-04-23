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
  explicit Engine(const std::string& raw_input);

  // Parses the string input for:
  // 1. The root note of the chord. (e.g. C in Cmaj7(#11) )
  // 2. The quality of the chord (e.g. kMajor in Cmaj7(#11) )
  // 3. Whether the chord is a seventh (true for ^^)
  // 4. Any extensions/alterations specified (like a #11 for ^^)
  // Returns a chord symbol created with these options.
  static ChordSymbol GetChordFromString(const std::string& chord_str);

  // Prints all the chords with all their scales for testing purposes.
  friend std::ostream& operator<<(std::ostream& os, Engine& engine);

 private:
  // All chords the user entered.
  std::vector<ChordSymbol> chords_;
};

} // namespace scalefinder

#endif  // FINALPROJECT_ENGINE_H
