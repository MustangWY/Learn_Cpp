#include<iostream>
#include"mytime.h"
int main(){
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;

    cout<<"Planning time: ";
    planning.Show();
    cout<<endl;

    cout<<"Coding time: ";
    coding.Show();
    cout<<endl;

    cout<<"Fixing time: ";
    fixing.Show();
    cout<<endl;

    cout<<"Total time: ";
    total = coding.Sum(fixing);
    total.Show();
    
    cout<<endl;


    return 0;
}