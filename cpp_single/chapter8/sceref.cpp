#include<iostream>
using namespace std;
int main(void){

    int rats = 101;
    int &rodents = rats;

    cout<<"rats = "<<rats;
    cout<<" , redens = "<<rodents<<endl;
    cout<<"rats address = "<<&rats<<" , rodents address = "<<&rodents<<endl;

    int bunnies = 50;
    rodents = bunnies;
    cout<<"bunnies = "<<bunnies<<endl;
    cout<<"rodents = "<<rodents<<endl;
    cout<<"rats = "<<rats<<endl;
    cout<<"rats address = "<<&rats<<" , rodents address = "<<&rodents<<endl;
    cout<<"bunnies address = "<<&bunnies;
    int* pt = &rats;
    

    return 0;
}