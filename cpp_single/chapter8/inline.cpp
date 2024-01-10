#include<iostream>
using namespace std;
inline double square(double x){ return x*x; }//内联函数
int main(void){
    double a,b;
    double c =13.0;
    a = square(5.0);
    b = square(13.0);
    cout<<"a = "<<a<<", b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
    cout<<"c square = "<<square(c++)<<endl;
    cout<<"Now c = "<<c<<endl;
    return 0;
}