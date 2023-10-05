#include<iostream>
using namespace std;
const double ProfitRate1=0.1;
const double ProfitRate2=0.05;
int main(void){
    double Daphne_invest,Daphne_Total;
    double Cleo_invest,Cleo_Total;
    Daphne_invest=Cleo_invest=Daphne_Total=Cleo_Total=100.0;
    int year=1;
    while(Daphne_Total>=Cleo_Total){
        Daphne_Total+=Daphne_invest*ProfitRate1;
        Cleo_Total+=Cleo_Total*ProfitRate2;
        year++;
        
    }
    cout<<"It has been "<<year<<" years\n";
    cout<<"Daphne now has :"<<Daphne_Total<<'$'<<endl;
    cout<<"Cleo now has : "<<Cleo_Total<<'$'<<endl;


    return 0;
}