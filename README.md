# ScaleFinder Lite

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)



ScaleFinder Lite is a practice tool for musicians that determines what scales are valid to use over any given chord. While intended for
jazz improvisers, it can also be used in a classical composition context.

### Features:

- Supports all **standard practice chord qualities**: major, minor, diminished, augmented, and half-diminished
- Can spell out all pitches in a given scale with correct **enharmonic equivalents** (including bb and ##)
- Contains a **piano visualizer** to intuitively view generated scales
- Can **play back scale audio** on a simple triangle wave

### Usage:

Simply enter a chord by inputting its:
- Tonic (e.g. C in Cmaj7#11)
- Quality (e.g. Major in Cmaj7#11)
- Whether it is a seventh chord or triad
- Extensions (e.g. #11, alt, b9)    
    
*For dominant seventh chords like C7, choose the "dom" quality.*

*Ninth chords (like C9) should be entered as 7th chords unless the ninth is altered. Major 6th chords are equivalent
to Maj7 chords.*

#### Supported Qualities:

| Symbol | Quality |
| ------------ | ------------- |
| M | Major |
| m | Minor |
| "+" | Augmented |
| o | Diminished |
| 0 | Half-Diminished |
| dom | Dominant 7th |

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Cale Wolf - [`caleqw2@illinois.edu`](mailto:caleqw2@illinois.edu)