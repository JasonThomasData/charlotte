#!/usr/bin/env bash

cd lib

# Install wiringPi dependency
sudo apt-get purge wiringpi
git clone git://git.drogon.net/wiringPi
./wiringPi/build

git clone git@github.com:eranpeer/FakeIt.git
cp FakeIt/single_header/standalone/fakeit.hpp ./

git clone git@github.com:catchorg/Catch2.git
cp Catch2/single_include/catch.hpp ./

# Install the robot program and tests in bin
cd ../
make
make clean
