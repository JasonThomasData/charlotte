all: objects exe_objects exe

phony: all clean

objects: build/servo_driver.o build/leg_driver_base.o build/leg_driver_02.o build/leg_driver_13.o build/robot.o build/builder.o
exe_objects: build/test_servo.o build/test_leg.o build/charlotte.o
exe: test_servo test_leg charlotte



build/servo_driver.o: src/servo/servo_driver.cpp
	g++ -c -std=c++14 src/servo/servo_driver.cpp -o build/servo_driver.o

build/leg_driver_base.o: src/leg/leg_driver_base.cpp
	g++ -c -std=c++14 src/leg/leg_driver_base.cpp -o build/leg_driver_base.o

build/leg_driver_02.o: src/leg/leg_driver_02.cpp
	g++ -c -std=c++14 src/leg/leg_driver_02.cpp -o build/leg_driver_02.o

build/leg_driver_13.o: src/leg/leg_driver_13.cpp
	g++ -c -std=c++14 src/leg/leg_driver_13.cpp -o build/leg_driver_13.o

build/builder.o: src/builder/builder.cpp
	g++ -c -std=c++14 src/builder/builder.cpp -o build/builder.o

build/robot.o: src/robot/robot.cpp
	g++ -c -std=c++14 src/robot/robot.cpp -o build/robot.o



build/test_servo.o: src/exe/test_servo.cpp
	g++ -c -std=c++14 src/exe/test_servo.cpp -o build/test_servo.o

build/test_leg.o: src/exe/test_leg.cpp
	g++ -c -std=c++14 src/exe/test_leg.cpp -o build/test_leg.o

build/charlotte.o: src/exe/charlotte.cpp
	g++ -c -std=c++14 src/exe/charlotte.cpp -o build/charlotte.o



test_servo:
	g++ -std=c++14 build/servo_driver.o build/test_servo.o -o bin/test_servo -lwiringPi -pthread
test_leg:
	g++ -std=c++14 build/servo_driver.o build/leg_driver_base.o build/leg_driver_02.o build/leg_driver_13.o build/test_leg.o build/robot.o build/builder.o -o bin/test_leg -lwiringPi -pthread
charlotte:
	g++ -std=c++14 build/servo_driver.o build/leg_driver_base.o build/leg_driver_02.o build/leg_driver_13.o build/robot.o build/builder.o build/charlotte.o -o bin/charlotte -lwiringPi -pthread



clean:
	\rm build/*

