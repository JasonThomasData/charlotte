use <../../Writescad/Write.scad>

////////////////////////
// MODULES

module screw_hole(x,y)
{
    r = 1;
    translate([x,y,0])
        circle(r);
}

module screw_buffer(x,y,z)
{
    inner_r = 1;
    outer_r = 2;
    height = 3;
    translate([x,y,z])
        linear_extrude(0,0,height)
            difference()
            {
                circle(outer_r);
                circle(inner_r);
            }
}

module all_screw_holes()
{
    //Pi Board holes
    screw_hole(3,18);
    screw_hole(63,18);
    screw_hole(63,72);
    screw_hole(3,72);
    //leg holes
    screw_hole(3,3);
    screw_hole(3,87);
    screw_hole(87,87);
    screw_hole(87,3);
}

module all_screw_buffers(z)
{
    //Pi Board buffers
    screw_buffer(3,18,z);
    screw_buffer(63,18,z);
    screw_buffer(63,72,z);
    screw_buffer(3,72,z);
}

module arrow()
{
    triangle_shape = [
        [0, 0],
        [20, 25],
        [20, 10],
        [50, 10],
        [50, 0]
    ];
    mirror([0, 90])
        polygon(points=triangle_shape);
    polygon(points=triangle_shape);
}

module base(base_width, base_thickness, arrow_pos)
{
    difference()
    {
        square(base_width);
        translate(arrow_pos)
            arrow(arrow_pos);
    }
}

module text(base_width)
{   
    translate([7, base_width-11, 2])
        write("0");
    translate([base_width-10, base_width-10, 2])
        write("1");
    translate([base_width-10, 6, 2])
        write("2");
    translate([7, 6, 2])
        write("3");
}

////////////////////////
// GLOBALS

base_thickness = 3;
base_width = 90;
arrow_pos = [18,45];

////////////////////////
// RENDERS


all_screw_buffers(base_thickness);
difference()
{
    linear_extrude(0,0,base_thickness)
        difference()
        {
            base(base_width, base_thickness, arrow_pos);
            all_screw_holes();
        }
    text(base_width);
}
