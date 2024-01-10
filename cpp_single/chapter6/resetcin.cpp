#include <iostream>
using namespace std;
int main(void){
    int num1,num2;
    cout<<"First number :";
    cin>>num1;
    cin.clear();//reset input
    while(cin.get() != '\n');//get rid of bad input
    cout<<"Second number :";
    cin>>num2;
    cout<<"num1 = "<<num1<<" num2 = "<<num2;
    return 0;
}