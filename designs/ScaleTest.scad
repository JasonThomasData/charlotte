////////////////////////////
// SCALE TEST
// Check model is 8mm wide, with circle 6mm wide, 3mm high

linear_extrude(height=3)
    difference() {
        square([8,8]);
        translate([4,4,0])
            circle(r=3, $fn=100);
    }
