#include<iostream>
#include"mytime01.h"
Time::Time(){
    hours = minutes = 0;
}
Time::Time(int h, int m){
    hours = h;
    minutes = m;
}
void Time::AddMin(int m){
    minutes+=m;
    hours+=minutes/60;
    minutes %= 60;
}

void Time::AddHr(int H){
    hours += H;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}



void Time::Show () const {
    std::cout<<hours<<" hours "<<minutes<<" minutes. \n";
}


Time Time::operator+(const Time &T) const{
    Time sum;
    sum.minutes = minutes + T.minutes;
    sum.hours = hours + T.hours + sum.minutes/60;
    sum.minutes %= 60; 
    return sum;

}