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

module motor() {
    screws();
    body();
}

//////////////////////////
// LEG

module leg(width)
{
    thickness = 5;
    length = 60;
    points = [
        [0, 0],
        [0, length],
        [1, length],
        [width, length / 2],
        [width, 0]
    ];

    linear_extrude(height = thickness)
        difference()
        {
            polygon(points = points);
            translate([6, 2.5])
                motor();
        }
}

module schampfer()
{
    y = 56;
    x = 0;
    z = 5;
    angle = -45;

    translate([x, y, z])
        rotate([angle, 0, 0])
            linear_extrude(height = 5)
                square([10, 10]);
}

module text(width, fontsize)
{
    translate([width-0.5, 1.5, 1.5])
        rotate([90, 0, 90])
            write("bottom", h = fontsize);
}

//////////////////////////
// GLOBALS

width = 16;
fontsize = 3;

//////////////////////////
// RENDER

difference()
{
    leg(width);
    schampfer();
}
text(width, fontsize);