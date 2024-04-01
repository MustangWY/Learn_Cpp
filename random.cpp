#include<iostream>
#include<ctime>
using namespace std;
int main(void){
        char ch;
       cout<<"Enter a letter:";
       cin>>ch;
     cin.get();
      ch -= 32;
      cout<<"converted into: "<<ch<<endl;


    return 0;
}