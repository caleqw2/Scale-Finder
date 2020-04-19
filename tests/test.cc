// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <scalefinder/example.h>
#include <scalefinder/pitch.h>

#include <catch2/catch.hpp>

using scalefinder::Pitch;

TEST_CASE("Random sanity test", "[random]") {
  const float random = cinder::randFloat();
  REQUIRE(0. <= random);
  REQUIRE(random <= 1.);
  std::cout << "Hi!" << std::endl;
}

TEST_CASE("Pitch string constructor") {
  //REQUIRE(Pitch("C3").to_string() == "C3");
  //REQUIRE(Pitch("Cbb7").to_string() == "Cbb7");
  //REQUIRE(Pitch("A#2").to_string() == "A#2");
  Pitch pitch = Pitch("D2");
  std::cout << pitch << std::endl;
  Pitch haha = Pitch("D2");
  std::cout << haha << std::endl;

  std::vector<int> vec = {1, 2, 3};
  Pitch vec_pitch = Pitch(vec);
  std::cout << vec_pitch << std::endl;

  REQUIRE(haha == vec_pitch);
}