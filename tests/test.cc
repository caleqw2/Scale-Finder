// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <scalefinder/example.h>
#include <scalefinder/pitch.h>

#include <catch2/catch.hpp>

using scalefinder::Pitch;

TEST_CASE("Pitch constructors") {
  REQUIRE(Pitch("C3").to_string() == "C3");
  REQUIRE(Pitch("Cbb7").to_string() == "Cbb7");
  REQUIRE(Pitch("A#2").to_string() == "A#2");

  REQUIRE(Pitch(1, 2, 4).to_string() == "D3");
}

TEST_CASE("Pitch equality operators") {
  REQUIRE(Pitch("C3") == Pitch("C3"));
  REQUIRE(Pitch("C3") != Pitch("C4"));
  REQUIRE(Pitch("C3") <= Pitch("C4"));
  REQUIRE(Pitch("C3") < Pitch("C4"));
  REQUIRE(Pitch("C3") >= Pitch("C2"));
  REQUIRE(Pitch("C3") > Pitch("Cb3"));
  REQUIRE(Pitch("C#3") < Pitch("Db3"));
}