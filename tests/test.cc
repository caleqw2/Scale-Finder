// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <scalefinder/chord_symbol.h>
#include <scalefinder/engine.h>
#include <scalefinder/interval.h>
#include <scalefinder/pitch.h>
#include <scalefinder/scale.h>

#include <catch2/catch.hpp>

#include "scalefinder/scaletype.h"

using scalefinder::Pitch;
using scalefinder::Interval;
using scalefinder::Scale;
using scalefinder::ScaleType;
using scalefinder::Engine;
using scalefinder::ChordSymbol;

// Pitch tests

/*
TEST_CASE("Pitch constructors") {
  SECTION("Valid input") {
    REQUIRE(Pitch("C3").ToString() == "C3");
    REQUIRE(Pitch("Cbb7").ToString() == "Cbb7");
    REQUIRE(Pitch("A#2").ToString() == "A#2");
  }
  SECTION("Invalid input") {
    REQUIRE_THROWS(Pitch(""));
    REQUIRE_THROWS(Pitch("Hello"));
    REQUIRE_THROWS(Pitch("H4"));
    REQUIRE_THROWS(Pitch("Cbbb"));
    REQUIRE_THROWS(Pitch("C11"));
  }
}

TEST_CASE("Pitch equality operators") {
  REQUIRE(Pitch("C3") == Pitch("C3"));
  REQUIRE(Pitch("C3") != Pitch("C4"));
  REQUIRE(Pitch("C3") != Pitch("C#3"));
  REQUIRE(Pitch("Db3") != Pitch("C#3"));
}

TEST_CASE("Pitch Keynum Functions") {
  SECTION("Getting keynum of a pitch") {
    REQUIRE(Pitch("C4").Keynum() == 60);
    REQUIRE(Pitch("C#4").Keynum() == 61);
  }
  SECTION("Creating pitch from keynum") {
    Pitch cnat = Pitch::FromKeynum(60, "None");
    REQUIRE(cnat == Pitch("C4"));
    Pitch csharp = Pitch::FromKeynum(61, "#");
    REQUIRE(csharp == Pitch("C#4"));
    Pitch dflat = Pitch::FromKeynum(61, "b");
    REQUIRE(dflat == Pitch("Db4"));
    // You can't spell a C with a single flat. It must be Dbb.
    REQUIRE_THROWS(Pitch::FromKeynum(60, "b"));
  }
}

// Interval tests

TEST_CASE("Intervals") {
  Interval interval_1 = Interval("m5");
  REQUIRE(interval_1.ToString() == "m5");
  Interval interval_2 = Interval("M6");
  REQUIRE(interval_2.ToString() == "M6");
  Interval interval_3 = Interval("oo2");
  REQUIRE(interval_3.ToString() == "oo2");
}

TEST_CASE("Interval transposition") {
  Pitch p = Interval("P5").Transpose(Pitch("C#5"));
  REQUIRE(p == Pitch("G#5"));
  Pitch p2 = Interval("m3").Transpose(Pitch("C3"));
  REQUIRE(p2 == Pitch("Eb3"));
}

// Scale/Engine Tests

TEST_CASE("Scale constructor") {
  Scale scale = Scale(Pitch("Ab4"), ScaleType::kAeolian);
  REQUIRE(scale.ToString() == "Ab Minor: [Ab, Bb, Cb, Db, Eb, Fb, Gb, Ab]");
}

TEST_CASE("Getting chord from a string") {
  ChordSymbol chord = Engine::GetChordFromString("C#m7");
  Engine engine = Engine("Cm7 B F7b9 BbM7 F07");
  std::string expected_out = "Chord: Cm7\n"
      "Scales:\n"
      "  C Dorian Minor: [C, D, Eb, F, G, A, Bb, C]\n"
      "  C Melodic Minor: [C, D, Eb, F, G, A, B, C]\n"
      "  C Minor: [C, D, Eb, F, G, Ab, Bb, C]\n"
      "\n"
      "Chord: B\n"
      "Scales:\n"
      "  B Mixolydian: [B, C#, D#, E, F#, G#, A, B]\n"
      "\n"
      "Chord: F7b9\n"
      "Scales:\n"
      "  F Mixolydian: [F, G, A, Bb, C, D, Eb, F]\n"
      "\n"
      "Chord: BbM7\n"
      "Scales:\n"
      "  Bb Major: [Bb, C, D, Eb, F, G, A, Bb]\n"
      "\n"
      "Chord: F07\n"
      "Scales:\n"
      "  F Locrian: [F, Gb, Ab, Bb, Cb, Db, Eb, F]\n"
      "  F Super Locrian: [F, G, Ab, Bb, Cb, Db, Eb, F]\n\n";

  std::stringstream ss;
  ss << engine;
  std::string output = ss.str();

  REQUIRE(output == expected_out);
}

 */

TEST_CASE("Debugging a diminished chord problem") {
  ChordSymbol symbol = ChordSymbol(Pitch("C4"), scalefinder::ChordQual::kDiminished, false, "None", "Chord!");
}