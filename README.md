This is the initial code to make a robot with a Raspberry Pi. The robot will have four legs attached
to a central body, like half of a spider. The robot's legs will move in coordination so that
opposing digits move at once.

### Install

To install dependencies and build the project, run `./install.sh`
That will also clean up the build objects.

### Build

Type ```make``` and hope for the best. If it's a success, your executable will appear at
```bin/charlotte```.

When you're done, clean it up with ```make clean```.

### Tests

At the moment, all tests are for the servos. All in /bin/test_*.

### Licence

MIT Licence, all clauses apply, credit Jason Thomas 2017.
