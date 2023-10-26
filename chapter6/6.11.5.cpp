#include<iostream>
using namespace std;
const double tier1_rate = 0.0;
const double tier2_rate = 0.1;
const double tier3_rate = 0.15;
const double tier4_rate = 0.2;
int main(void){
    double income,tax=0;
    cout<<"Please enter your income: "<<endl;
    while (cin>>income)
    {   
        if (income<0)
        {
            break;
        }else if (income<=5000)
        {
            cout<<"Your tax is 0 tvarps."<<endl;
            tax=0;
        }else if (income>5000&&income<=15000)
        {
            tax = 5000*tier1_rate+(income-5000)*tier2_rate;
            cout<<"Your tax is "<<tax<<"tvarps."<<endl;
            tax=0;
        }else if (income>15000&&income<=35000)
        {
            tax = 5000*tier1_rate+10000*tier2_rate+(income-15000)*tier3_rate;
            cout<<"Your tax is "<<tax<<"tvarps."<<endl;
            tax=0;
        }else if (income>35000)
        {
            tax = 5000*tier1_rate+10000*tier2_rate+20000*tier3_rate+(income-35000)*tier4_rate;
            cout<<"Your tax is "<<tax<<"tvarps."<<endl;
            tax=0;
        }
        cout<<"Please enter your income: "<<endl;
        cout<<"To end, enter a letter or a negative number."<<endl;   
    }
    cout<<"quiting"<<endl;
    return 0;
}