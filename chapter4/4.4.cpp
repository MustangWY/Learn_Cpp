#include<iostream>
#include<string>
using namespace std;
int main(){
    string FirstName;
    string LastName;
    cout<<"Enter your First Name: ";
    getline(cin,FirstName);
    //cin>>FirstName;
    cout<< "Enter your Last name: ";
    getline(cin,LastName);
    //cin>>LastName;
    LastName+=" , ";
    LastName+=FirstName;
    cout<<"Heres the information in a single string: "<<LastName;
    return 0;
}
