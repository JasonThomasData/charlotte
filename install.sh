#!/usr/bin/env bash

cd lib

# Install wiringPi dependency
sudo apt-get purge wiringpi
git clone git://git.drogon.net/wiringPi
cd wiringPi
./build
cd ../
cd ../

# Install the project in bin/
make
make clean
