#include<iostream>
using namespace std;
struct travel_time
{
    int hours;
    int minutes;
};

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time);

const int mins_per_hour = 60;
int main(void){
    travel_time day1={5,45};
    travel_time day2={4,55};
    travel_time trip; 
    trip = sum(day1,day2);
    cout<<"Two days total:\n";
    show_time(trip);
    travel_time day3 = {4,32};
    cout<<"Three days total:\n";
    show_time(sum(trip,day3));
    return 0;
}
travel_time sum(travel_time t1, travel_time t2){

    travel_time total;
    total.minutes = (t1.minutes+t2.minutes)%mins_per_hour;
    total.hours = (t1.hours+t2.hours)+(t1.minutes+t2.minutes)/mins_per_hour;
    return total;
}
void show_time(travel_time t1){
    cout<<t1.hours<<" hours "<<t1.minutes<<"minutes. "<<endl;
}

