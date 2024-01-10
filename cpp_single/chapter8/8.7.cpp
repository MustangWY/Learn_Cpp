#include <iostream>
using namespace std;

template<class T>
void SumArray(T arr[], int n);

template<class T>
void SumArray(T * arr[],int n);

struct debts
{   
    char name[50];
    double amount;
    /* data */
};

int main(void){
    int things[6] = {13, 31, 103, 301, 310, 130};
    SumArray(things,6);//使用模板A
    struct debts mr_E[3] = {
        {"Ima Wolfe",2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout",1800.0}
    };
    double *pd[3];
    for (int i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }
    SumArray(pd,3);//使用模板B
    return 0;
}

template<class T>
void SumArray(T arr[], int n){
    cout<<"Template A: "<<endl;
    int sum;
    for (int i = 0; i < n; i++)
    {
       sum+=arr[i];
    }
    cout<<sum<<endl;

}

template<class T>
void SumArray(T * arr[],int n){
    cout<<"Template B"<<endl;
    double sum;
    for (int i = 0; i < n; i++)
    {   
        sum+=*arr[i];
        /* code */
    }
    cout<<sum<<endl;

}  