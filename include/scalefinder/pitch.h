//
// Created by Cale Wolf on 4/19/20.
//

#ifndef FINALPROJECT_SCALEFINDER_PITCH_H
#define FINALPROJECT_SCALEFINDER_PITCH_H

#include <string>
#include <vector>

namespace scalefinder {

const static std::string kLetterNames[] = {"C", "D", "E", "F", "G", "A", "B"};
const static std::string kAccidentalNames[] = {"bb", "b", "", "#", "##"};
const static std::string kOctaveNames[] = {"00", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

const static int kNumPitchLetters = 7;
const static int kNumOctaves = 11;

const static std::string kNoAcciPitches[] = {"C", "C#", "D", "Eb", "E", "F", "F#", "G", "Ab", "A", "Bb", "B"};
const static std::string kSharpPitches[] = {"B#", "C#", "x", "D#", "x", "E#", "F#", "x", "G#", "x", "A#", "x"};
const static std::string kFlatPitches[] = {"x", "Db", "x", "Eb", "Fb", "x", "Gb", "x", "Ab", "x", "Bb", "Cb"};
const static std::string kDoubleSharpPitches[] = {"x", "B##", "C##", "x", "D##", "x", "E##", "F##", "x", "G##", "x", "A##"};
const static std::string kDoubleFlatPitches[] = {"Dbb", "x", "Ebb", "Fbb", "x", "Gbb", "x", "Abb", "x", "Bbb", "Cbb", "x"};

const static std::string kEmptyPitchStringMessage = "Tried to create empty string";
const static std::string kBadAcciFormat = "Your accidental was formatted incorrectly.";
const static std::string kInvalidAcci = "That accidental doesn't work with that pitch class.";
const static std::string kInvalidPitchString = "Invalid pitch string.";
const std::string kKeynumOutOfRange = "Midi keynum out of bounds";
const std::string kInvalidKeynum = "Invalid midi number";

/**
 * A musical pitch.
 */
class Pitch {
 public:
  // Default
  Pitch();
  /**
   * Initialize from a string (i.e. Pitch("C#5))
   */
  explicit Pitch(const std::string& pitch_str);

  friend std::ostream& operator<<(std::ostream& os, Pitch& pitch);
  bool operator==(const Pitch& other) const;
  bool operator!=(const Pitch& other) const;

  std::string ToString();

  std::string GetNote();
  int GetAccidental();
  int GetLetter();

  /**
   * Returns the int MIDI key number of that pitch
   * @return The keynum
   */
  int Keynum();

  /**
   * Creates a pitch from a keynum.
   * @param keynum The integer keynum of the new pitch.
   * @param acci A preferred accidental (like C# vs Db)
   * @return The new Pitch.
   */
  static Pitch FromKeynum(int keynum, const std::string& acci);

  static bool IsNumeric(const std::string& value);

  /**
   * Gets the hertz frequency of that pitch.
   * @return The frequency in hertz as a double.
   */
  double Hertz();

 private:
  int letter_ = -1; /** 0-6, for letters ['C', 'D', 'E', 'F', 'G', 'A', 'B'] */
  int accidental_ = -1; /** 0-4 for accidentals ['bb', 'b', '', '#', '##'] */
  int octave_ = -1; /** 0-10, ['00', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'] */
  int pos_ = -1; /** A unique integer to help in comparing pitches. */

  /** Helper function in constructor to determine octave_. */
  static int FindOctaveIndex(const std::string& copy, int pos);
};

}  // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_PITCH_H
