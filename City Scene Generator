#include "library.h"

int pick_number()
{
	int x = random_in_range(0, 23);
	return x;
}

void pick_color(int x)
{
	if (x <= 20)
	{
		if (x >= 17)
		{
			set_pen_color(color::orange);
		}
		else
		{
			if (x >= 11)
			{
				set_pen_color(color::light_blue);
			}
			else
			{
				if (x >= 6)
				{
					set_pen_color(color::dark_blue);
				}
				else
				{
					set_pen_color(color::black);
				}
			}
		}
	}
	else
	{
		set_pen_color(color::black);
	}
}

void drawcircle(int degrees)
{
	if (degrees < 360)
	{
		note_position();
		turn_right_by_degrees(1);
		move_distance(0.5);
		drawcircle(degrees + 1);
	}
}

void celestialobject(int x)
{
	if (x <= 20)
	{
		if (x >= 17)
		{
			move_to(500, 100);
			start_shape();
			drawcircle(0);
			set_pen_color(color::yellow);
			fill_shape();
		}
		else
		{
			if (x >= 11)
			{
				move_to(500, 100);
				start_shape();
				drawcircle(0);
				set_pen_color(color::yellow);
				fill_shape();
			}
			else
			{
				if (x >= 6)
				{
					move_to(200, 100);
					start_shape();
					drawcircle(0);
					set_pen_color(color::yellow);
					fill_shape();
				}
				else
				{
					move_to(200, 100);
					start_shape();
					drawcircle(0);
					set_pen_color(color::white);
					fill_shape();
				}
			}
		}
	}
	else
	{
		move_to(500, 100);
		start_shape();
		drawcircle(0);
		set_pen_color(color::white);
		fill_shape();
	}
}

void background()
{
	start_shape();
	move_to(0, 0);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(700);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(500);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(700);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(500);
	note_position();
	int x = pick_number();
	pick_color(x);
	fill_shape();
	celestialobject(x);
}

void draw_window(double width, double height, double x, double y, double r, double g, double b)
{
	start_shape();
	move_to(x, y);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(width);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(height);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(width);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(height);
	set_pen_color(r, g, b);
	fill_shape();
}

void window_row(double wnumber, double width, double height, double x, double y, double r, double g, double b)
{
	if (wnumber > 0)
	{
		draw_window(width, height, x, y, r, g, b);
		x = x + width + 3;
		window_row(wnumber - 1, width, height, x, y, r, g, b);
	}
}

void floors(double fnumber, double wnumber, double width, double height, double x, double y, double r, double g, double b)
{
	if (fnumber > 0)
	{
		y = y - 2 * height;
		floors(fnumber - 1, wnumber, width, height, x, y, r, g, b);
	}
}

void random_color()
{
	double r = (double)rand() / (RAND_MAX);
	double g = (double)rand() / (RAND_MAX);
	double b = (double)rand() / (RAND_MAX);
	set_pen_color(r, g, b);
}

int wnumber(double width)
{
	return 3;
}

int wheightconstant(double width)
{
	if (width <= 125)
	{
		if (width <= 100)
		{
			int wheight = 1.25;
			return wheight;
		}
		else
		{
			int wheight = 1;
			return wheight;
		}
	}
	else
	{
		int wheight = 0.75;
		return wheight;
	}
}

void roof(double width, double height);

void firstfloor(double x, double y, double width);

void building(double x, double y, double width)
{
	double r = (double)rand() / (RAND_MAX);
	double g = (double)rand() / (RAND_MAX);
	double b = (double)rand() / (RAND_MAX);
	int windownumber = wnumber(width);
	double wwidth = (width - 4 - (windownumber - 1) * 3) / windownumber;
	double fnumber = 0.75;
	double windowheight = wheightconstant(width)*wwidth;
	double height = (2 * fnumber)*windowheight + 15;
	start_shape();
	move_to(x, y);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(width);
	note_position();
	turn_left_by_degrees(90);
	draw_distance(height);
	note_position();
	turn_left_by_degrees(90);
	draw_distance(width);
	note_position();
	turn_left_by_degrees(90);
	draw_distance(height);
	turn_right_by_degrees(180);
	random_color();
	fill_shape();
	floors(fnumber, windownumber, wwidth, windowheight, x + 2, y - 10 - windowheight, r, g, b);
	move_to(x, y);
	roof(width, 1.5*windowheight + 15);
	firstfloor(x, y, width);
}

void draw_street()
{
	start_shape();
	move_to(0, 490);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(700);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(10);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(700);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(10);
	note_position();
	set_pen_color(color::grey);
	fill_shape();
}

int randomwidth()
{
	int width = random_in_range(75, 125);
	return width;
}

void greenbar()
{
	start_shape();
	move_to(0, 485);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(700);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(5);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(700);
	note_position();
	turn_right_by_degrees(90);
	draw_distance(5);
	note_position();
	set_pen_color(color::light_green);
	fill_shape();
}

void officerow(double x, double y)
{
	if ((x + 125) < 700)
	{
		int width = randomwidth();
		building(x, y, width);
		x = x + width + 50;
		officerow(x, y);
	}
}

void firstfloor(double x, double y, double width)
{
	double r = (double)rand() / (RAND_MAX);
	double g = (double)rand() / (RAND_MAX);
	double b = (double)rand() / (RAND_MAX);
		double wwidth = (width - 40)/2;
		int windowheight = wheightconstant(width)*wwidth;
		draw_window(wwidth, windowheight, x + 5, y - 10 - windowheight, r, g, b);
		draw_window(wwidth, windowheight, x + wwidth + 35, y - 10 - windowheight, r, g, b);
		move_to(x, y);
		turn_right_by_degrees(90);
		move_distance(10 + wwidth);
		start_shape();
		note_position();
		turn_left_by_degrees(90);
		draw_distance(10 + windowheight);
		note_position();
		turn_right_by_degrees(90);
		draw_distance(20);
		note_position();
		turn_right_by_degrees(90);
		draw_distance(10 + windowheight);
		note_position();
		turn_right_by_degrees(90);
		draw_distance(20);
		note_position();
		turn_right_by_degrees(90);
		set_pen_color(color::red);
		fill_shape();
}

void roof(double width, double height)
{
	move_distance(height);
	turn_left_by_degrees(90);
	move_distance(5);
	start_shape();
	note_position();
	turn_right_by_degrees(180);
	move_distance(width + 10);
	note_position();
	turn_left_by_degrees(180);
	move_distance((width/2)+5);
	turn_right_by_degrees(90);
	move_distance(25);
	note_position();
	turn_left_by_degrees(180);
	move_distance(25);
	turn_right_by_degrees(90);
	move_distance((width / 2) + 5);
	note_position();
	turn_right_by_degrees(90);
	set_pen_color(color::mauve);
	fill_shape();
}

void tree1(const int wwidth, const int wheight)
{
			set_pen_width(1);
			set_pen_color(color::brown);
			int treex = 80;
			while ((treex + 75) < 700)
			{
				int treey = wheight - 40;
				fill_rectangle(treex, treey - 60, 8, 90, color::brown);
				set_pen_width(4);
				int count = 400;
				while
					(count > 0)
				{
					move_to(treex, treey - 60);
					int a = random_in_range(50, 255);
					int color = make_color_int(0, a, 0);
					set_pen_color(color);
					int x = random_in_range(-30, 30);
					int y = random_in_range(-30, 25);
					move_relative(x, y);
					draw_point();
					count--;
				}
				treex = treex + 125;
			}

}

void main()
{
	make_window(700, 500);
	background();
	draw_street();
	greenbar();
	officerow(10, 490);
	int x = number_generator();
	while (x > 0)
	{
		tree1(500, 500);
		x--;
	}
}
