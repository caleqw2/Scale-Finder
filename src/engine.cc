//
// Created by Cale Wolf on 4/22/20.
//

#include "scalefinder/engine.h"

#include <iostream>
#include <sstream>

namespace scalefinder {

Engine::Engine() = default;

Engine::Engine(const std::string& raw_input) {

  // Splits the input stream by spaces into a vector.
  std::istringstream iss(raw_input);
  std::vector<std::string> chord_strs(
      (std::istream_iterator<std::string>(iss)),
      std::istream_iterator<std::string>());

  // Creates a ChordSymbol for each string and adds it to chords_.
  for (const std::string& chord_str : chord_strs) {
    chords_.push_back(GetChordFromString(chord_str));
  }
}

ChordSymbol Engine::GetChordFromString(const std::string& chord_str) {
  std::size_t index_of_qual = chord_str.find_first_of("Mm0+o7");

  Pitch root = Pitch(chord_str.substr(0, index_of_qual) + "4");

  ChordQual qual;
  switch(chord_str[index_of_qual]) {
    case 'M': qual = ChordQual::kMajor; break;
    case 'm': qual = ChordQual::kMinor; break;
    case '0': qual = ChordQual::kHalfDiminished; break;
    case '+': qual = ChordQual::kAugmented; break;
    case 'o': qual = ChordQual::kDiminished; break;
    default: qual = ChordQual::kDominant; break;
  }

  bool is_seventh = chord_str.find('7') != std::string::npos;

  std::string extensions;
  if (is_seventh) {
    extensions = chord_str.substr(index_of_qual + 2);
  } else {
    extensions = chord_str.substr(index_of_qual + 1);
  }

  return ChordSymbol(root, qual, is_seventh, extensions, chord_str);
}

std::ostream& operator<<(std::ostream& os, Engine& engine) {
  for (ChordSymbol chord : engine.chords_) {
    os << "Chord: " + chord.GetName() << std::endl;
    os << "Scales:" << std::endl;
    for (Scale scale : chord.GetScales()) {
      os << "  " << scale << std::endl;
    }
    os << std::endl;
  }
  return os;
}

std::vector<ChordSymbol> Engine::GetChords() {
  return chords_;
}

void Engine::AddChord(const ChordSymbol& new_chord) {
  chords_.push_back(new_chord);
}

} // namespace scalefinder