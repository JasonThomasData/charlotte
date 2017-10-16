all: objects exe

phony: all clean

objects: build/servo_driver.o build/leg_driver_base.o build/leg_driver_02.o build/leg_driver_13.o  build/test_servo.o build/test_leg.o #build/interface.o


exe: test_servo test_leg #interface


build/servo_driver.o: src/servo/servo_driver.cpp
	g++ -c -std=c++14 src/servo/servo_driver.cpp -o build/servo_driver.o

build/leg_driver_base.o: src/leg/leg_driver_base.cpp
	g++ -c -std=c++14 src/leg/leg_driver_base.cpp -o build/leg_driver_base.o

build/leg_driver_02.o: src/leg/leg_driver_02.cpp
	g++ -c -std=c++14 src/leg/leg_driver_02.cpp -o build/leg_driver_02.o

build/leg_driver_13.o: src/leg/leg_driver_13.cpp
	g++ -c -std=c++14 src/leg/leg_driver_13.cpp -o build/leg_driver_13.o

build/test_servo.o: src/exe/test_servo.cpp
	g++ -c -std=c++14 src/exe/test_servo.cpp -o build/test_servo.o

build/test_leg.o: src/exe/test_leg.cpp
	g++ -c -std=c++14 src/exe/test_leg.cpp -o build/test_leg.o

build/interface.o: src/exe/interface.cpp
	g++ -c -std=c++14 src/exe/interface.cpp -o build/interface.o


test_servo:
	g++ -std=c++14 build/servo_driver.o build/test_servo.o -o bin/test_servo -lwiringPi -pthread -lcrypt -lrt

test_leg:
	g++ -std=c++14 build/servo_driver.o build/leg_driver_base.o build/leg_driver_02.o build/test_leg.o -o bin/test_leg -lwiringPi -pthread -lcrypt -lrt


interface:
	g++ -std=c++14 build/servo_driver.o build/leg_driver_base.o build/interface.o -o bin/interface -lwiringPi -pthread -lcrypt -lrt


clean:
	\rm build/*

