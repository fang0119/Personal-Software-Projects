#include "library.h"

const double pi = acos(-1.0);

int timeString = get_clock_time();            // gets current time and date from computer
int dateString = get_calendar_date();

int year = dateString/10000;
int month = (dateString%10000) / 100;
int day = dateString%100;                     // parses current time/date into human format
int hour = timeString/10000;
int minute = (timeString%10000)/100;
int second = (timeString%100);
int contHour = hour%12;

string months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};


void draw_Marks(int count) {

set_pen_color(color::black);
set_pen_width(3);
move_to(250,300);
set_heading_degrees(30*count);    // mark drawing function
move_distance(135);
draw_distance(8);
if (count<11)
    {draw_Marks(count+1);}

}

void arc (double degree) {

	move_to(250 + 155 * sin(degree * (pi/180.0)), 300 - 155 * cos(degree * (pi/180.0)) );
	draw_point();

	if (degree < ( (contHour/12.0) * 360 + ((minute/60.0) * 30 ) ) ) {
	 
	arc(degree+1);

	}

}

void clock_Face() {

move_to(250,300);
set_pen_color(color::black);
set_pen_width(300);
draw_point();                     // creates a circle
set_pen_color(color::white);
set_pen_width(294);
draw_point();

draw_Marks(0);             // draws 12 marks around the circle


move_to(190,120);
set_font_size(40); 
write_string(contHour);
write_string(":");
if (minute<10) {write_string(0);}
write_string(minute);
write_string(" ");
if (hour<12) {write_string("a.m.");}
else {write_string ("p.m.");}

move_to(170,500);
write_string(months[month-1]);
write_string(" ");
write_string(day);
if (day==1)
    {write_string("st");}
if (day==2)
	{write_string("nd");}
if (day==3)
    {write_string("rd");}
else
    {write_string("th");}

move_to(220,550);
write_string(year);

move_to(250,152);
set_pen_color(color::red);
set_pen_width(11);
arc(0);


}

void clock() {

while (true) {

timeString = get_clock_time();            // gets current time and date from computer
dateString = get_calendar_date();
year = dateString/10000;
month = (dateString%10000) / 100;
day = dateString%100;                     // parses current time/date into human format
hour = timeString/10000;
minute = (timeString%10000)/100;
second = (timeString%100);
contHour = hour%12;

move_to(250,300);
set_pen_color(color::blue);
set_pen_width(2);                // seconds hand
set_heading_degrees(360 * (second/60.0));
draw_distance(117);

move_to(250,300);
set_pen_color(color::black);
set_pen_width(6);                // minute hand
set_heading_degrees(360 * (minute/60.0));
draw_distance(105);

move_to(250,300);
set_pen_color(color::black);
set_pen_width(6);                // hour hand
set_heading_degrees(360 * (hour/12.0) + 30*(minute/60.0));
draw_distance(81);

if (second%60 == 0) {

fill_rectangle(170, 70, 250, 60, color::white);

set_pen_color(color::black);
move_to(190,120);
set_font_size(40); 
write_string(contHour);
write_string(":"); 
if (minute<10) {write_string(0);}
write_string(minute);
write_string(" ");
if (hour<12) {write_string("a.m.");}
else {write_string ("p.m.");}


} 

wait(0.1);
move_to(250,300);
set_pen_color(color::white);
set_pen_width(240);
draw_point();


}



}



void main() {

	make_window(500,600);
	clock_Face();
	clock();

}
