//
// Created by Cale Wolf on 4/22/20.
//

#include "scalefinder/chord_symbol.h"

#include <utility>

namespace scalefinder {

ChordSymbol::ChordSymbol(Pitch root, ChordQual qual, bool is_seventh,
                         std::vector<std::string> extensions)
    : root_(root) { // TODO: What?
  qual_ = qual;
  is_seventh_ = is_seventh;
  extensions_ = std::move(extensions);
  PopulateScales();
}
void ChordSymbol::PopulateScales() {}
} // namespace scalefinder