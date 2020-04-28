//
// Created by Cale Wolf on 4/22/20.
//

#ifndef FINALPROJECT_SCALEFINDER_CHORD_QUALS_H
#define FINALPROJECT_SCALEFINDER_CHORD_QUALS_H

namespace scalefinder {

/**
 * Represents all the supported types of chords to be input.
 */
enum class ChordQual {
  kMajor, kMinor, kAugmented, kDiminished, kHalfDiminished, kDominant
};

} // namespace scalefinder

#endif  // FINALPROJECT_SCALEFINDER_CHORD_QUALS_H
