#include<iostream>
#include"Person.h"

using namespace std;

int main(void){
    Person one;
    Person two("Symthecraft");
    Person three("Dimwiddy", "Sam");
    one.show();
    cout<<endl;
    one.FormalShow();
    cout<<endl;
    two.show();
    two.FormalShow();
    return 0;
}