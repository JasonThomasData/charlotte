//////////////////////////
// MOTOR - HOLDER

module screws() {

    radius = 1.2;
    distance = 28;

    translate([0,0])
        circle(r=radius, $fn=10);
    translate([0,distance])
        circle(r=radius, $fn=10);
}

module body() {

    width = 12.5;
    length = 23.5;

    translate([-width/2, 2.5])
        square([width, length]);
}

module motor() {
    screws();
    body();
}

//////////////////////////
// LEG

module leg() {
    thickness = 5;
    length = 33;
    width = 16;
    points = [[0,0],[0,length],[width,length],[width,0]];

    linear_extrude(height=thickness)
        difference() {
            polygon(points=points);
            translate([6, 2.5])
                motor();
        }
}

//////////////////////////
// SPIN SHAFT

module spin_shaft() {
    distance = 37;
    small_radius = 1.2;
    large_radius = 3;
    small_depth = 4;
    large_depth = 2;

    translate([-4,distance,10])
        linear_extrude(height=small_depth)
                circle(r=small_radius, $fn=10);
    translate([-4,distance,14])
        linear_extrude(height=large_depth)
                circle(r=large_radius, $fn=10);
}

//////////////////////////
// SPIN SHAFT - SOCKET

module spin_shaft_socket() {
    distance = 33;
    width = 8;
    depth = 5;

    translate([-8,distance,11])
            linear_extrude(height=depth)
                square([width, width]);
}

//////////////////////////
// RENDER

leg();
difference() {
    rotate([0,90,0])
        spin_shaft_socket();
    rotate([0,90,0])
        spin_shaft();
}