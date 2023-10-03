#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char FirstName[20];
    char LastName[20];
    cout<<"Enter your First Name: ";
    cin.getline(FirstName,20);
    cout<< "Enter your Last name: ";
    cin.getline(LastName,20);
    strcat(LastName," , ");
    strcat(LastName,FirstName);
    cout<<"Heres the information in a single string: "<<LastName;
    return 0;
}