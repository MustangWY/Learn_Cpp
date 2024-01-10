#include<iostream>
const int seasons = 4;
using namespace std;
struct exp
{
   double exp[seasons];
};
const char* Snames[4] = {"Spring","Summer","Fall","Winter"};
void fill(double ar[],int n);
void show(const double ar[],int n);
void fill_stru(exp* ex);
void show_stru(exp ex);
using namespace std;
int main(){
    double expense[seasons];
    exp year;
    //fill(expense,seasons);
    //show(expense,seasons);    
    fill_stru(&year);
    show_stru(year);                                                                                     
    return 0;
}
void fill(double ar[] ,int n){
    for (int i = 0; i < n; i++)
    {   
        cout<<"Enter "<<Snames[i]<<" expenses ";
        cin>>ar[i];//*pt[i] wrong
        /* code */
    }
    

}
void show(const double ar[],int n){
    double total = 0.0;
    cout<<"Expense: \n";
    for (int  i = 0; i < n; i++)
    {   
        cout<<Snames[i]<<" : $"<<ar[i]<<"\n";
        total+=ar[i];
        /* code */
    }
    cout<<"Total expense: $"<<total<<endl;
}

void fill_stru(exp *ex){
    for (int i = 0; i < seasons; i++)
    {   
        cout<<"Enter "<<Snames[i]<<" expenses ";
        cin>>ex->exp[i];
        /* code */
    }
    
}
void show_stru(exp ex){
    double total = 0.0;
    cout<<"Expense: \n";
    for (int  i = 0; i < seasons; i++)
    {   
        cout<<Snames[i]<<" : $"<<ex.exp[i]<<"\n";
        total+=ex.exp[i];
        /* code */
    }
    cout<<"Total expense: $"<<total<<endl;
}