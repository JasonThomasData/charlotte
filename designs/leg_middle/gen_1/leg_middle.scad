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
    length = 48;
    width = 16;

    linear_extrude(height=thickness)
        difference() {
            square([width, length]);
            translate([6, 2.5])
                motor();
        }
}

//////////////////////////
// SPIN SHAFT

module spin_shaft() {
    distance = 43;
    small_radius = 1.2;
    large_radius = 2.5;
    small_depth = 3;
    large_depth = 2;

    translate([11,distance,0])
        linear_extrude(height=small_depth)
            circle(r=small_radius, $fn=10);
    translate([11,distance,small_depth])
        linear_extrude(height=large_depth)
            circle(r=large_radius, $fn=10);
}

//////////////////////////
// RENDER

difference() {
    leg();
    spin_shaft();
}