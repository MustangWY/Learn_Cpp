#include<iostream>
#include<array>
using namespace std;
const int Arrsize = 100;
int main(void){
    array<long double , Arrsize> factorials;
    factorials[1]=factorials[0]=1LL;
    for(int i=2;i<=Arrsize;i++){
        factorials[i]=i*factorials[i-1];
    }
    for(int i = 0;i<=Arrsize;i++){
        cout<<i<<"! = "<<factorials[i]<<endl;
    }

    return 0;
}