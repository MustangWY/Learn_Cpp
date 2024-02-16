#include<iostream>
using namespace std;
void remote_access();
int tom = 3;
int dick = 30;
static int harry = 300; //only visible in twofile1.cpp
int main (void){
    cout << "main() reports the following addresse: \n";
    cout << &tom << " = tom. " << &dick << " = dick. " << &harry<< " = harry. \n"; 
    remote_access();
    return 0;
}