//
// Created by Cale Wolf on 4/24/20.
//

#ifndef FINALPROJECT_SCALEFINDER_KEY_H
#define FINALPROJECT_SCALEFINDER_KEY_H

#include <string>

namespace scalefinder {

class PianoKey {
 public:
  PianoKey(const std::string& name, int num, int xloc, bool is_white);
  const std::string& GetName() const;
  int GetKeynum() const;
  int GetXloc() const;
  bool IsWhite() const;
 private:
  std::string name_;
  int keynum_;
  int xloc_;
  bool is_white_;

};

} // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_KEY_H
