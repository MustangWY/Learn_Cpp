#include<iostream>
#include"list.h"
using namespace std;
int main(void){
    List list;
    Item num;
    for (int i = 0; i < 3; i++)
    {   
        cout<<"Please enter a number:\n";
        cin>>num;
        list.Add(num);
        list.visit(visit_Item);
        /* code */
    }
    
    
    return 0;
}