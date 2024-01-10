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
void rect_to_polar(const rect *pr1,polar *pp1);//const 不修改原始数据
int main(){
    rect rplace;
    polar pplace;
    cout<<"Enter the x and y values: ";
    while (cin>>rplace.x>>rplace.y)
    {   
        rect_to_polar(&rplace,&pplace);
        show_polar(pplace);
        cout<<"Enter the next two number(q to quit)";
        /* code */
    } 
    
}

void rect_to_polar(const rect *pr1,polar *pp1){
    pp1->distance=sqrt(pr1->x*pr1->x+pr1->y*pr1->y);
    pp1->angle=atan2(pr1->y,pr1->x);
    
    
}
void show_polar(const polar* p1){
    const double rad_to_deg = 57.29577951;
    cout<<"Distance: "<<p1->distance<<endl;
    cout<<"Angle: "<<p1->angle*rad_to_deg<<" degrees. \n";

}                                                                                                                                                                                                                                                                                                                                                                                                               