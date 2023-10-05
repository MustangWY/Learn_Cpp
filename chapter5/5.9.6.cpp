#include<iostream>
using namespace std;
const int year = 3;
const int months = 12;
int main(void){
    const char* month[months]={
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
    int sell[year][months];
    for (int i = 0; i < year; i++)
    {
        for (int j = 0; j < months; j++)
        {
            cout<<"Please enter "<<"year "<<i+1<<' '<<month[j]<< " sold number:";
            cin>>sell[i][j];
            /* code */
        }
        
        ;
        /* code */
    }
    int sum_year[year];
    int sum=0;
    for (int i = 0; i < year; i++)
    {   
        for (int j = 0; j < months; j++)
        {
            sum_year[i]+=sell[i][j];
            
            /* code */
        }
        cout<<"The book sold "<<sum_year[i]<<" copies in year"<<i<<endl;
    sum+=sum_year[i];
        /* code */
    }
    cout<<"The book sold "<<sum<<" books in total."<<endl;
    return 0;
}