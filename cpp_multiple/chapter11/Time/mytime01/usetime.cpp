#include<iostream>
#include"mytime01.h"
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
    total = coding + fixing;
    total.Show();
    
    cout<<endl;

    Time morefixing(3,28);
    cout<<"More fixing time: ";
    morefixing.Show();

    total = morefixing.operator+(total);

    cout<<"morefixing.operator+(total): ";

    total.Show();
    



    return 0;
}