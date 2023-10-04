#include <iostream>
#include <ctime>
using namespace std;
int main(void){
    cout<<"enter delay time: ";
    float sec;
    cin>>sec;
    clock_t delay=sec*CLOCKS_PER_SEC;
    cout<<"starting\a\n";
    clock_t start=clock();
    while (clock()-start<delay);
    cout<<"done\a\n";
    
    return 0;
}