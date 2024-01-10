#include <iostream>
using namespace std;
void swapr(int &a, int &b);
void swapp(int* p , int *q);
void swqpv(int a, int b);
int main(void){
    int wallet1 = 300;
    int wallet2 = 350;
    cout<<"wallet 1 = "<<wallet1<<endl;
    cout<<"wallet 2 = "<<wallet2<<endl;

    cout<<"using reference to swap contents: "<<endl;
    swapr(wallet1,wallet2);
    cout<<"wallet 1 = "<<wallet1<<endl;
    cout<<"wallet 2 = "<<wallet2<<endl;

    cout<<"using pointers to swap contents: "<<endl;
    swapp(&wallet1,&wallet2);
    cout<<"wallet 1 = "<<wallet1<<endl;
    cout<<"wallet 2 = "<<wallet2<<endl;
    
    cout<<"Trying to swap by passing value"<<endl;
    swqpv(wallet1,wallet2);
    cout<<"wallet 1 = "<<wallet1<<endl;
    cout<<"wallet 2 = "<<wallet2<<endl;
    

    return 0;
}

void swapr(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void swapp(int* p , int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void swqpv(int a, int b){
    int temp;
    temp = a;
    a = b;
    b= temp;
}