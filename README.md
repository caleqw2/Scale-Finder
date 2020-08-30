# ScaleFinder Lite :musical_score:

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)

ScaleFinder Lite is a practice tool for musicians that determines what scales are valid to use over any given chord. While intended for
jazz improvisers, it can also be used in a classical composition context.

### Features:

- Supports all **standard practice chord qualities**: major, minor, diminished, augmented, and half-diminished
- Can spell out all pitches in a given scale with correct **enharmonic equivalents** (including bb and ##)
- Contains a **piano visualizer** to intuitively view generated scales :musical_keyboard:
- Can **play back scale audio** on a simple triangle wave :sound:

### Usage:

Simply enter a chord by inputting its:
- Tonic (e.g. C in Cmaj7#11)
- Quality (e.g. Major in Cmaj7#11)
- Whether it is a seventh chord or triad
- Extensions (e.g. #11, alt, b9)

After entry, chords and their respective scales can be viewed in dropdown menus and will be displayed on the piano
when selected.
    
*For dominant seventh chords like C7, choose the "dom" quality.*

*Ninth chords (like C9) should be entered as 7th chords unless the ninth is altered. Major 6th chords are equivalent
to Maj7 chords.*

#### Supported Qualities:

| Symbol | Quality |
| ------------ | ------------- |
| M | Major |
| m | Minor | 
| dom | Dominant 7th |
| + | Augmented |
| o | Diminished |
| 0 | Half-Diminished |

### Build Information:

Dependencies: [Cinder](https://libcinder.org), [ImGui](https://github.com/simongeilfus/Cinder-ImGui)

Requires CMake but that is a part of the project file.

#### Cinder Setup
1. Download the latest version of Cinder onto your Mac and extract that into a folder.
2. Open the ~/Cinder folder in CLion and hit the "build" button to build Cinder.
3. Place the folder of this project into ~/Cinder/my-projects/
4. If you get an error saying "permission denied", manually change the executable to 
my-projects/final-project-caleqw2/cmake-build-debug/Debug/cinder-myapp/Contents/MacOS/cinder-myapp

#### ImGui Setup

Fork the Cinder-ImGui repo and download it into ~/Cinder/Blocks/. That is all.

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Cale Wolf - [`caleqw2@illinois.edu`](mailto:caleqw2@illinois.edu)
