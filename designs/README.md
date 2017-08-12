Download and install OpenScad to compile the `.scad` files into `.stl`.

The original files that were printed are in gen_1. The next files to test are in gen_2. When a shape is printed, following designs are a new generation.

The gen_1 objects were printed on a MakerBot and the results were pretty good.
The settings were:

    Quality          standard
    Infill           70%
    number of shells 2
    Layer width      0.2 mm

To test the print, check that the ScaleTest.stl prints to 8mm wide, 3mm high, circle diameter of
6mm.

Where there are non-symmetrical elements in an .stl, you'll need to print an equal number of
mirrored objects.

The WriteScad code was from [here](https://www.thingiverse.com/thing:16193)

### Printing the base

When you print the base, it will be best to use a heated glass plate. Since the shape covers such a large area, the bottom will cool as the top is still hot and it will warp.