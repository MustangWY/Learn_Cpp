#include<iostream>
#include<cmath>
#include"coordin.h"
using namespace std;

polar rect_to_polar(rect r1){
    polar p;
    p.distance = sqrt(r1.x*r1.x+r1.y*r1.y);
    p.angle = atan2(r1.y,r1.x);
    return p;
    
}
void show_polar(polar p1){
    const double rad_to_deg = 57.29577951;
    cout<<"Distance: "<<p1.distance<<endl;
    cout<<"Angle: "<<p1.angle*rad_to_deg<<" degrees. \n";

}