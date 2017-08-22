all: objects exe

phony: all clean

objects: build/servo_driver.o build/leg_driver.o build/test_servo.o build/test_leg.o

exe: test_servo test_leg


build/servo_driver.o: src/servo/servo_driver.cpp
	g++ -c -std=c++14 src/servo/servo_driver.cpp -o build/servo_driver.o

build/leg_driver.o: src/leg/leg_driver.cpp
	g++ -c -std=c++14 src/leg/leg_driver.cpp -o build/leg_driver.o

build/test_servo.o: src/exe/test_servo.cpp
	g++ -c -std=c++14 src/exe/test_servo.cpp -o build/test_servo.o

build/test_leg.o: src/exe/test_leg.cpp
	g++ -c -std=c++14 src/exe/test_leg.cpp -o build/test_leg.o



test_servo:
	g++ -std=c++14 build/servo_driver.o build/test_servo.o -o bin/test_servo -lwiringPi -pthread

test_leg:
	g++ -std=c++14 build/servo_driver.o build/leg_driver.o build/test_leg.o -o bin/test_leg -lwiringPi -pthread



clean:
	\rm build/*

