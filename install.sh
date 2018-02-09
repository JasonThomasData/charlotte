#!/usr/bin/env bash

# Install dependencies
cd lib
  sudo pacman -R wiringpi
  git clone git://git.drogon.net/wiringPi

  cd wiringPi
    ./build
  cd ../

  git clone git@github.com:eranpeer/FakeIt.git
  cp FakeIt/single_header/standalone/fakeit.hpp ./

  git clone git@github.com:catchorg/Catch2.git
  cp Catch2/single_include/catch.hpp ./
cd ../

# Install the robot program and tests in bin
make
make clean
