#include<iostream>
using namespace std;
int main(void){
    const char* month[12]={
        "January",
        "Feburary",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int sell[12];
    for (int i = 0; i < 12; i++)
    {
        cout<<"Please enter "<<month[i]<< " sold number: ";
        cin>>sell[i];
        /* code */
    }
    int sum=0;
    for (int i = 0; i < 12; i++)
    {   
        sum+=sell[i];
        /* code */
    }
    cout<<"The book sold "<<sum<<" copies in this year."<<endl;
    return 0;
}