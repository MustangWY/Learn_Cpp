#include <iostream>
using namespace std;
const int arrsize = 20;
int main (void){
    long long factorials[arrsize];
    factorials[0]=factorials[1]=1;
    for(int i=2;i<=20;i++){
        factorials[i]=i*factorials[i-1];
    }
    for(int i = 0;i<=20;i++){
        cout<<i<<"! = "<<factorials[i]<<endl;
    }
    return 0;
}