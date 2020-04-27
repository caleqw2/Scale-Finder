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
// Test interval constructor
// Test interval Transpose method
// Test GetSemitones

// Scale tests
// Test scale construction/printing

// Engine test
// Test creating an Engine from a bunch of chords.


TEST_CASE("Intervals") {
  Interval interval = Interval("m5");
  //std::cout << interval << std::endl;
}

//

TEST_CASE("The Big Test!") {
  Scale scale = Scale(Pitch("Ab4"), ScaleType::kAeolian);
  //std::cout << scale.ToString() << std::endl;
}

TEST_CASE("Getting chord from a string") {
  ChordSymbol chord = Engine::GetChordFromString("C#m7");
  Engine engine = Engine("Cm7 B F7b9 BbM7 F07");
  //std::cout << engine << std::endl;
}