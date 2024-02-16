#include<iostream>

extern int tom;
static int dick = 10;
int harry = 200;

void remote_access(void){
    std::cout<<"remote_access() reports the following addrresses: \n";
    std::cout<<&tom<<" = tom. "<<&dick<<" = &dick. ";
    std::cout<<&harry<<" = &harry.\n";

}
