#include<iostream>
using namespace std;
int main(void){
    int i,sum = 0;
    do{
        cout<<"Please enter a number:";
        cin>>i;
        sum+=i;
        cout<<"sum = "<<sum<<endl;
        cout<<"Enter 0 to stop"<<endl;
    }while (i!=0);
    return 0;
}