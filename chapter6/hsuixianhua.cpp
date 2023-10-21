#include<iostream>
using namespace std;
int main (void){
    int x,y,z;
    for (int  i = 100; i < 1000; i++)
    {
        x=(int)i/100;
        y=(int)(i/10)-x*10;
        z=i-x*100-y*10;
        //cout<<"x="<<x<<"y="<<y<<"z="<<z<<endl;
        if(i==x*x*x+y*y*y+z*z*z){
            cout<<i<<" is a petal number\n";
        }
    }
    

    return 0;
}