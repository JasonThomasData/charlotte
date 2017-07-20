all: build/servo_driver.o build/leg_driver.o build/walk.o walk

phony: all clean

build/servo_driver.o: src/servo/servo_driver.cpp
	g++ -c -std=c++14 src/servo/servo_driver.cpp -o build/servo_driver.o

build/leg_driver.o: src/leg/leg_driver.cpp
	g++ -c -std=c++14 src/leg/leg_driver.cpp -o build/leg_driver.o

build/walk.o: src/exe/walk.cpp
	g++ -c -std=c++14 src/exe/walk.cpp -o build/walk.o

walk:
	g++ -std=c++14 build/servo_driver.o build/leg_driver.o build/walk.o -o bin/walk -lwiringPi -pthread

clean:
	\rm build/*

