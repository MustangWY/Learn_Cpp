#include<fstream>
#include <iostream>
int main(void){
    using namespace std;
    char automobile[50];
    int year;
    double a_price;
    double d_price;
    ofstream outFile;

    cout<<"enter the make and model of automobile: ";
    cin.getline(automobile,50);
    cout<<"enter the model year: ";
    cin>>year;
    cout<<"ebter the original asking price: ";
    cin>>a_price;
    d_price=a_price*0.913;

    cout<<"Make and model: "<<automobile<<endl;
    cout<<"Year: "<<year<<endl;
    cout<<"Was asking: "<<a_price<<endl;
    cout<<"Now asking: "<<d_price<<endl;
    return 0;
}