// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <scalefinder/pitch.h>
#include <scalefinder/interval.h>
#include <scalefinder/scale.h>
#include <scalefinder/scaletype.h>
#include <catch2/catch.hpp>

using scalefinder::Pitch;
using scalefinder::Interval;
using scalefinder::Scale;
using scalefinder::ScaleType;

/*

TEST_CASE("Pitch constructors") {
  REQUIRE(Pitch("C3").ToString() == "C3");
  REQUIRE(Pitch("Cbb7").ToString() == "Cbb7");
  REQUIRE(Pitch("A#2").ToString() == "A#2");

  REQUIRE(Pitch(1, 2, 4).ToString() == "D3");
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

TEST_CASE("Intervals") {
  Interval interval = Interval("m5");
  std::cout << interval << std::endl;
}

 */

TEST_CASE("The Big Test!") {
  Scale scale = Scale(Pitch("Ab4"), ScaleType::kMajor);
  std::cout << scale.ToString() << std::endl;
}