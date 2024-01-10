#include<iostream>
using namespace std;
int main (){
    const int ArSize=20;
    char name[ArSize];
    char dessert[ArSize];
    cout<<"Enter your name:\n";
    //cin>>name;
    //cin.getline(name,ArSize);//getline
    cin.get(name,ArSize);
    cin.get();
    //cin.get(name,ArSize).get();//拼合
    cout<<"Enter yout favorite dessert:\n";
    //cin>>dessert;
    //cin.getline(dessert,ArSize);//getline
    cin.get(dessert,ArSize);
    cout<<"I have some delicious "<<dessert<<
    " for you "<<name;
    return 0;
}