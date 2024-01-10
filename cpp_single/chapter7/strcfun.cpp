#include<iostream>
#include<cmath>
using namespace std;
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
int main(){
    rect rplace;
    polar pplace;
    cout<<"Enter the x and y values: ";
    while (cin>>rplace.x>>rplace.y)
    {   
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout<<"Enter the next two number(q to quit)";
        /* code */
    }
    
}

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