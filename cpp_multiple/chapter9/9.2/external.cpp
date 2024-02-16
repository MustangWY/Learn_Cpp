#include<iostream>
#include"support.h"
using namespace std;
double warming = 0.3; //external variable

int main(void){
    cout<<"Global warming is "<<warming<<" degrees."<<endl;
    update(0.1);
    cout<<"Global warming is "<<warming<<" degrees."<<endl;
    local();
    return 0;
}
