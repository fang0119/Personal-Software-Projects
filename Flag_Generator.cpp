#include "library.h"

void draw_one_star(double sidelength, double xval, double yval)
{ 
 start_shape();
 move_to(xval,yval);
 note_position();

 set_heading_degrees(162);
 draw_distance(sidelength);
 note_position();

 turn_left_by_degrees(72);
 draw_distance(sidelength);
 note_position();

 turn_right_by_degrees(144);
 draw_distance(sidelength);
 note_position();

 turn_left_by_degrees(72);
 draw_distance(sidelength);
 note_position();

 turn_right_by_degrees(144);
 draw_distance(sidelength);
 note_position();

 turn_left_by_degrees(72);
 draw_distance(sidelength);
 note_position();

 turn_right_by_degrees(144);
 draw_distance(sidelength);
 note_position();

 turn_left_by_degrees(72);
 draw_distance(sidelength);
 note_position();

 turn_right_by_degrees(144);
 draw_distance(sidelength);
 note_position();

 turn_left_by_degrees(72);
 draw_distance(sidelength);
 note_position();

 fill_shape();
}

void draw_6_stars (double sidelength, double separation, double verticalSeparation, double indent, double xval, double yval, double windowLength, double windowHeight)
{
    draw_one_star(sidelength, xval, yval);
	draw_one_star(sidelength, xval + separation, yval);
	draw_one_star(sidelength, xval + 2*separation, yval);
	draw_one_star(sidelength, xval + 3*separation, yval);
	draw_one_star(sidelength, xval + 4*separation, yval);
	draw_one_star(sidelength, xval + 5*separation, yval);
}

void draw_5_stars (double sidelength, double separation, double verticalSeparation, double indent, double xval, double yval, double windowLength, double windowHeight)
{
    draw_one_star(sidelength, xval + indent, yval + verticalSeparation);
    draw_one_star(sidelength, xval + indent + separation, yval + verticalSeparation);
    draw_one_star(sidelength, xval + indent + 2*separation, yval + verticalSeparation);
    draw_one_star(sidelength, xval + indent + 3*separation, yval + verticalSeparation);
    draw_one_star(sidelength, xval + indent + 4*separation, yval + verticalSeparation);
}


void draw_11_stars (double sidelength, double separation, double verticalSeparation, double indent, double xval, double yval, double windowLength, double windowHeight)
{
	draw_6_stars(sidelength, separation, verticalSeparation, indent, xval, yval, windowLength, windowHeight);
	draw_5_stars(sidelength, separation, verticalSeparation, indent, xval, yval, windowLength, windowHeight);
}

void draw_50_stars (double sidelength, double separation, double verticalSeparation, double indent, double rowSpacing, double xval, double yval, double windowLength, double windowHeight)
{
    draw_11_stars(sidelength, separation, verticalSeparation, indent, xval, yval, windowLength, windowHeight);
	draw_11_stars(sidelength, separation, verticalSeparation, indent, xval, yval + rowSpacing, windowLength, windowHeight);
	draw_11_stars(sidelength, separation, verticalSeparation, indent, xval, yval + 2*rowSpacing, windowLength, windowHeight);
	draw_11_stars(sidelength, separation, verticalSeparation, indent, xval, yval + 3*rowSpacing, windowLength, windowHeight);
	draw_6_stars(sidelength, separation, verticalSeparation, indent, xval, yval + 4*rowSpacing, windowLength, windowHeight);
}


void draw_America(const double scale)
{
	const double size = scale * 100;
	const double length = size*1.9;
	const double width = size;
	const double stripe_width = size/13.0;
	
	make_window(1.9*size, size);
    
	set_pen_color(color::red);
	fill_rectangle(0.0, 0.0, 1.9*size, size/13.0);
	fill_rectangle(0.0, 2*stripe_width, 1.9*size, size/13.0);
	fill_rectangle(0.0, 4*stripe_width, 1.9*size, size/13.0);
	fill_rectangle(0.0, 6*stripe_width, 1.9*size, size/13.0);
	fill_rectangle(0.0, 8*stripe_width, 1.9*size, size/13.0);
	fill_rectangle(0.0, 10*stripe_width, 1.9*size, size/13.0);
	fill_rectangle(0.0, 12*stripe_width, 1.9*size, size/13.0);


	set_pen_color(color::blue);
	fill_rectangle(0.0, 0.0, 1.9*size * (2.0/5.0), size* (7.0/13.0));

	set_pen_color(color::white);
	draw_50_stars(size*0.02125, size*0.1326, size*0.053125, size*0.0663, size*0.1105, size*0.045, size*0.025, size*0.38, size*0.28);


}

void main()
{
	draw_America(5);   //scale factor 1-8
}
