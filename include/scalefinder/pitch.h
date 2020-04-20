//
// Created by Cale Wolf on 4/19/20.
//

#ifndef FINALPROJECT_SCALEFINDER_PITCH_H
#define FINALPROJECT_SCALEFINDER_PITCH_H

#include <string>
#include <vector>

namespace scalefinder {

const std::string kLetterNames[] = {"C", "D", "E", "F", "G", "A", "B"};
const std::string kAccidentalNames[] = {"bb", "b", "", "#", "##"};
const std::string kOctaveNames[] = {"00", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

class Pitch {
 public:
  // Initialize from a string (i.e. Pitch("C#5))
  explicit Pitch(const std::string& pitch_str);
  // Initialize from three ints, [letter, accidental, octave] (see below)
  explicit Pitch(int letter, int accidental, int octave);

  // Print operator
  friend std::ostream& operator<<(std::ostream& os, Pitch& pitch);

  // Equality operators
  bool operator==(const Pitch& other) const;
  bool operator!=(const Pitch& other) const;
  bool operator<=(const Pitch& other) const;
  bool operator>=(const Pitch& other) const;
  bool operator<(const Pitch& other) const;
  bool operator>(const Pitch& other) const;

  std::string ToString();

  // Returns the int MIDI key number of that pitch
  int Keynum();

  // Returns the pitch class (an int 1-12)
  int PitchClass();

  // Creates and returns a pitch from a keynum.
  // TODO: Implement this!!!
  static Pitch FromKeynum(int keynum, std::string acci);

 private:
  int letter_ = -1; // 0-6, for letters ['C', 'D', 'E', 'F', 'G', 'A', 'B']
  int accidental_ = -1; // 0-4 for accidentals ['bb', 'b', '', '#', '##']
  int octave_ = -1; // 0-10, ['00', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
  int pos_ = -1; // A unique integer to help in comparing pitches.

  // Helper function used to calculate pos_. Used in constructor.
  int GetPos();
  // Helper function to check if a string is numeric.
  static bool IsNumeric(const std::string& value);
  // Helper function in constructor to determine octave_.
  static int FindOctaveIndex(const std::string& copy, int pos);
};

}  // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_PITCH_H