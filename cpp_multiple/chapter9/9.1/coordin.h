#ifndef COORDIN_H_
#define COORDIN_H_
struct polar
{
    double distance;
    double angle;
};
struct rect
{   
    double x;
    double y;
    /* data */
};
void show_polar(polar p1);
polar rect_to_polar(rect r1);

#endif