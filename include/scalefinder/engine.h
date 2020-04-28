//
// Created by Cale Wolf on 4/22/20.
//

#ifndef FINALPROJECT_SCALEFINDER_ENGINE_H
#define FINALPROJECT_SCALEFINDER_ENGINE_H

#include <vector>

#include "chord_symbol.h"
namespace scalefinder {

/**
 * The backend engine that handles parsing of user input and determining
 * what chord symbols correlate to what chords.
 */
class Engine {
 public:
  Engine();

  /**
   * Takes in an un-formatted string of chords separated by spaces e.g. [Cmaj7 F6 Bbm9(#11)]
  // Splits it into a vector of strings.
  // Takes each single chord string and generates a ChordSymbol from it using GetChordFromString()
  // The ChordSymbol will populate it's scales list upon construction.
   * @param raw_input The string of chord input from the UI.
   */
  explicit Engine(const std::string& raw_input);

  /**
   * Parses the string input for:
   * 1. The root note of the chord. (e.g. C in Cmaj7(#11) )
   * 2. The quality of the chord (e.g. kMajor in Cmaj7(#11) )
   * 3. Whether the chord is a seventh (true for ^^)
   * 4. Any extensions/alterations specified (like a #11 for ^^)
   * @param chord_str The string input.
   * @return A ChordSymbol for that chord.
   */
  static ChordSymbol GetChordFromString(const std::string& chord_str);

  friend std::ostream& operator<<(std::ostream& os, Engine& engine);

  std::vector<ChordSymbol> GetChords();

 private:
  std::vector<ChordSymbol> chords_;
};

} // namespace scalefinder

#endif  // FINALPROJECT_ENGINE_H
