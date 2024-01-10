#include<iostream>
using namespace std;
double fun(double x,double y);
int main(void){
     double x,y;
    double result;
    cout<<"please enter two numbers: ";
    while (cin>>x>>y)
    {
        if (x==0||y==0)
            break;
        result = fun(x,y);
        cout<<"Result = "<<result<<endl;
        cout<<"please enter two numbers: ";
        /* code */
    }
    return 0;
}

double fun(double x,double y){
    
    double result;
    result = (2.0*x*y)/(x+y);
    return result;
}