use <../../Writescad/Write.scad>

//////////////////////////
// MOTOR - HOLDER

module screws()
{
    radius = 1.2;
    distance = 28;

    translate([0, 0])
        circle(r = radius, $fn = 10);
    translate([0, distance])
        circle(r = radius, $fn = 10);
}

module body()
{
    width = 12.5;
    length = 23.5;

    translate([-width / 2, 2.25])
        square([width, length]);
}

module motor()
{
    screws();
    body();
}

//////////////////////////
// LEG

module leg(width)
{
    thickness = 5;
    length = 33;
    
    points = [
        [0, 0],
        [0, length],
        [width, length],
        [width, 0]
    ];

    linear_extrude(height = thickness)
        difference()
        {
            polygon(points=points);
            translate([6, 2.5])
                motor();
        }
}

module text(width, fontsize)
{
    x = 0.5;
    y = 1.5;
    z = 1.5;

    translate([width - x, y, z])
        rotate([90, 0, 90])
            write("top", h = fontsize);
}

//////////////////////////
// SPIN SHAFT

module spin_shaft()
{
    small_radius = 1.2;
    large_radius = 3;
    small_depth = 3;
    large_depth = 2;
    x = 0;
    y = 37;
    z = 4;

    translate([x + large_depth, y, z])
        rotate([0, 90, 0])
            linear_extrude(height = small_depth)
                    circle(r = small_radius, $fn = 10);
    translate([x, y, z])
        rotate([0, 90, 0])
            linear_extrude(height = large_depth)
                circle(r = large_radius, $fn = 10);
}

module spin_shaft_socket()
{
    width = 8;
    depth = 5;
    x = 0;
    z = 8;
    y = 33;

    translate([x, y, z])
        rotate([0, 90, 0])
            linear_extrude(height = depth)
                square([width, width]);
}


//////////////////////////
// GLOBALS

width = 16;
fontsize = 3;

//////////////////////////
// RENDER

difference()
{
    spin_shaft_socket();
    spin_shaft();
}
leg(width);
text(width, fontsize);