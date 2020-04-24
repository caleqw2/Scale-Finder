//
// Created by Cale Wolf on 4/24/20.
//

#include "scalefinder/piano_key.h"

namespace scalefinder {

PianoKey::PianoKey(const std::string& name, int num, int xloc, bool is_white) {
  name_ = name;
  keynum_ = num;
  xloc_ = xloc;
  is_white_ = is_white;
}

const std::string& PianoKey::GetName() const { return name_; }
int PianoKey::GetKeynum() const { return keynum_; }
int PianoKey::GetXloc() const { return xloc_; }
bool PianoKey::IsWhite() const { return is_white_; }

} // namespace scalefinder