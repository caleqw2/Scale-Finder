//
// Created by Cale Wolf on 4/24/20.
//

#ifndef FINALPROJECT_SCALEFINDER_KEY_H
#define FINALPROJECT_SCALEFINDER_KEY_H

#include <string>

namespace scalefinder {

/**
 * Represents a piano key in the piano visualizer.
 */
class PianoKey {
 public:
  /**
   * The constructor.
   * @param name The pitch name.
   * @param num The integer Keynum of that key.
   * @param xloc The location of that key on the app grid.
   * @param is_white Whether it is a white key.
   */
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
