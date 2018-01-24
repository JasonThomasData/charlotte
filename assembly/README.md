These are the instructions for piecing together the hardware components of the robot.

### Materials

- 12 x sg90, Tower Pro, 180-degrees servo motors
- 36 female-male prototype wires. Prefer 12 black, 12 red and 12 different colours
- 1 x Raspberry Pi 3
- 1 x SD card, I think >= 8GB is good
- 1 x Arch Linux ARM 64b image, headless
- 2 x each leg component of the latest generation, 3D printed, check in designs (there should be 12 in total)
- 1 x base component, 3D printed
- 24 x M2 nuts and bolts, no less than 10mm in length

Installing Arch linux on the SD card is a job in itself, and there's a separate explainer [here]().

For the 3d-printed components, be sure to read the specs for each... the components will be light and strong enough.

### Assembling a servo and component (holder)

The servo shafts should be at the top end of the leg. See this arrangement of a middle component.

![pic_of_servo_assembly]()

### Assembling a leg

Each leg has three main parts, each consisting of a servo and a brace to hold it. Group them by whether or not they're file names include 'mirror' or not.

Each leg should have three servos, and each servo has its own signal wire, to receive PWM signals from the board. It should be orange, and there should also be a positive red and black ground wire. 

Have a look at this configuration, this is one of the normal legs without 'mirrored' in the filename.

![pic_of_leg_assembly](pics/pic_of_leg_assembly.jpg)

The servos will each come with one or more screws when you purchase them, and you can file down the tips of those screws to be more flat, so each is more like a bolt.

Screw them into the servo shafts, but not tight at first. It's important they're not tight at first, because you want to make sure the servo shafts are at the right angle before that.

You will want to know what the board's pin configuration is at this point, and the simplest way is to enter `GPIO` at the terminal. It should give you a table of your board's pin config. Use the wiringPi pin numbers.

For a normal leg, which is not a mirrored leg, use the Pi board's pins 0 (bottom), 1 (middle), and 2 (top) for the signal wires. When the servos are all connected run `./bin/test_leg`.

For a mirrored leg, it's the same, but you want to use pins 3 (bottom), 4 (midddle) and 5 (top), and run bin/leg_1_test -- this is no longer the case, update this

Each servo in each leg will do a series of things and then stop at the positions where the leg would be fully extended, so, you can now put the leg on a flat surface and screw the screws in tighter. You might want to use a mild adhesive, like some kind of thread-tight solution to make the screw, shaft and leg component stay in place.

With all servos screwed in tight, you can now hold the remaining servo shaft with a sideways pair of plyers, and the leg will do a complete turn walk cycle and then return to the fully extended position.

### Assembling the robot

With all the legs in place, you can screw the top servos underneath the printed board. The circle on the robot's base is for the servo's wires to feed through, and the wires should come out the top.

![pic_of_attached_leg](pics/pic_of_attached_leg.jpg)

The board, near each corner screw hole, has numbers. The normal, non-mirror legs, should be at positions 0 and 2, and the mirrored legs should go at positions 1 and 3. Leg 0 will be the front-right leg on the forward-facing robot, and the arrow is good if you're unsure. The legs go clockwise 0-3

Here's the board's pin arrangement for each leg:

    0:
        bottom: 0
        middle: 1
        top: 2
    1:
        bottom: 3
        middle: 4
        top: 5
    2:
        bottom: 6
        middle: 7
        top: 8
    3:
        bottom: 9
        middle: 10
        top: 11


You can change those pin numbers, and the place to do that is in the RobotFactory, but I don't see a need.

The first, leg 0, will be the front-right leg on the forward-facing robot, (the arrow is no accident) and the legs will continue around in a clockwise fashion.

I used a small breadboard in my robot, but you can do what you want, because I'm not your dad and can't tell you how to live your life.

Your robot should not power its servos from the board's power supply. Doing so creates a serial circuit and the board will turn off. The servos should have access to a 3.3v power supply. That supply's positive wire should come into one pin on the board and go out to the 12 servo's positive wires, on the same rail so the wires are all connected in parallel. Same for negative.

The servos shouldn't do anything until they get sent a signal and they've got their own internal relay for that, but I guess you could choose to have a power supply switch.

For protecting the pins of the Pi board, it's good to have a resistor for the signal wire, and 1k ohm seems to work well. This is the reason I chose to have a breadboard so doing the resistor thing is easy.

Here's what the board

### Power

I'm still figuring this one out.
