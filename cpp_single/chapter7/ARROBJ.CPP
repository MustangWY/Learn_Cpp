#include<iostream>
#include<array>
#include<string>
using namespace std;
const int seasons = 4;
const array<string,seasons> Snames = {"Spring","Summer","Fall","Winter"};
void fill(array<double,seasons> *pt);
void show(array<double,seasons> da);
using namespace std;
int main(){
    array<double,seasons> expense;
    fill(&expense);       
    show(expense);                                                                                               
    return 0;
}
void fill(array<double,seasons> *pt){
    for (int i = 0; i < seasons; i++)
    {   
        cout<<"Enter "<<Snames[i]<<" expenses ";
        cin>>(*pt)[i];//*pt[i] wrong
        /* code */
    }
    

}
void show(array<double,seasons> da){
    double total = 0.0;
    cout<<"Expense: ";
    for (int  i = 0; i < seasons; i++)
    {   
        cout<<Snames[i]<<" : $"<<da[i]<<"\n";
        total+=da[i];
        /* code */
    }
    cout<<"Total expense: $"<<total<<endl;
}






