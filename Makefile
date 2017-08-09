all: build/servo_driver.o build/leg_driver.o build/test_leg.o test_leg

phony: all clean

build/servo_driver.o: src/servo/servo_driver.cpp
	g++ -c -std=c++14 src/servo/servo_driver.cpp -o build/servo_driver.o

build/leg_driver.o: src/leg/leg_driver.cpp
	g++ -c -std=c++14 src/leg/leg_driver.cpp -o build/leg_driver.o

build/test_leg.o: src/exe/test_leg.cpp
	g++ -c -std=c++14 src/exe/test_leg.cpp -o build/test_leg.o

test_leg:
	g++ -std=c++14 build/servo_driver.o build/leg_driver.o build/test_leg.o -o bin/test_leg -lwiringPi -pthread

clean:
	\rm build/*

