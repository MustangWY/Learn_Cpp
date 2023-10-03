#include<iostream>
#include<array>
using namespace std;
int main (){
    array<double,3> grade;
    cout<<"Please enter your time: "<<endl;
    cout<<"lap 1: ";
    cin>>grade[0];
    cout<<"lap 2: ";
    cin>>grade[1];
    cout<<"lap 3: ";
    cin>>grade[2];
    double avg =(grade[0]+grade[1]+grade[2])/3;
    cout<<"You have run 3 laps"<<endl;
    cout<<"Your average time is "<<avg;

    return 0;
}