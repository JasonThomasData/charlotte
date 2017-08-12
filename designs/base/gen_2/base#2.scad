use <../../Writescad/Write.scad>

////////////////////////
// HOLES

/* This board is to be used for a Raspberry Pi 3. The base#1
 * produced a warped board, and future prints should use a
 * heated glass plate.
 */

module screw_hole(x, y, hole_r)
{
    translate([x,y,0])
        circle(hole_r, $fn=10);
}

module screw_buffer(x, y, z, hole_r)
{
    outer_r = hole_r + 1.5;
    height = 3;
    translate([x, y, z])
        linear_extrude(0, 0, height)
            difference()
            {
                circle(outer_r, $fn=10);
                circle(hole_r, $fn=10);
            }
}

module all_screw_holes(hole_r)
{
    //Pi Board holes
    screw_hole(3, 18, hole_r);
    screw_hole(63, 18, hole_r);
    screw_hole(63, 72, hole_r);
    screw_hole(3, 72, hole_r);
    //leg holes
    screw_hole(3, 3, hole_r);
    screw_hole(3, 87, hole_r);
    screw_hole(87, 87, hole_r);
    screw_hole(87, 3, hole_r);
}
// Note - lots of duplication between these two, try and clean this up module
module all_screw_buffers(z, hole_r)
{
    //Pi Board buffers
    screw_buffer(3, 18, z, hole_r);
    screw_buffer(63, 18, z, hole_r);
    screw_buffer(63, 72, z, hole_r);
    screw_buffer(3, 72, z, hole_r);
}

module wire_holes(base_width)
{
    translate([16, base_width-14, 0])
        circle(r=8);
    translate([base_width-16, base_width-14, 0])
        circle(r=8);
    translate([base_width-16, 14, 0])
        circle(r=8);
    translate([16, 14, 0])
        circle(r=8);
}

////////////////////////
// BASE

module arrow()
{
    triangle_shape = [
        [0, 0],
        [25, 30],
        [25, 12],
        [60, 12],
        [60, 0]
    ];
    mirror([0, 90])
        polygon(points=triangle_shape);
    polygon(points=triangle_shape);
}

module base(base_width, base_thickness, arrow_pos)
{
    difference()
    {
        difference()
        {
            square(base_width);
            translate(arrow_pos)
                arrow(arrow_pos);
        }
        wire_holes(base_width);
    }
}

module text(base_width, z)
{
    translate([5, base_width-9, z])
        write("0");
    translate([base_width-8, base_width-9, z])
        write("1");
    translate([base_width-8, 5, z])
        write("2");
    translate([5, 5, z])
        write("3");
}

////////////////////////
// GLOBALS

base_thickness = 3;
base_width = 90;
arrow_pos = [15, 45];
hole_r = 1.2;

////////////////////////
// RENDERS

all_screw_buffers(base_thickness, hole_r);
linear_extrude(0, 0, base_thickness)
    difference()
    {
        difference()
        {
            base(base_width, base_thickness, arrow_pos);
        }
        all_screw_holes(hole_r);
    }
text(base_width, base_thickness);
