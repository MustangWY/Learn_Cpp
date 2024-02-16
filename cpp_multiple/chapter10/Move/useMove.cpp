#include<iostream>
#include"Move.h"
using namespace std;
int main(void){
    Move a(3,4);
    cout<<"First position: ";
    a.showMove();
    Move b(4,5);
    cout<<"Second position: ";
    b.showMove();
    Move c = a.add(b);
    cout<<"After add position: ";
    c.showMove();
    

    return 0;
}