#include<iostream>
using namespace std;
int main(){
    int donuts=6;
    double cups=40.5;
    cout<<"donut value = "<<donuts<<endl;
    cout<<"donut adress = "<<&donuts<<endl;
    cout<<"cups value = "<<cups<<endl;
    cout<<"cups value = "<<&cups<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(double);
    return 0;
}