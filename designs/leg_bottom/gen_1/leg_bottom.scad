//////////////////////////
// MOTOR - HOLDER
// Quality - standard
// Infill 70%
// number of shells 2
//Layer width 0.2 mm

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
    length = 60;
    width = 16;
    points = [[0,0],[0,length],[width, length/2],[width,0]];

    linear_extrude(height=thickness)
        difference() {
            polygon(points=points);
            translate([6, 2.5])
                motor();
        }
}

module schampfer() {
    translate([0,33,5])
        rotate([-4.2,0,0])
            linear_extrude(height=5)
                square([35, 35]);
    translate([0,33.15,-5])
        rotate([3.9,0,0])
            linear_extrude(height=5)
                square([35, 35]);
}

//////////////////////////
// RENDER

difference() {
    leg();
    schampfer();
}