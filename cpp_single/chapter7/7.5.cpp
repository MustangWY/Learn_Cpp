#include<iostream>
using namespace std;
int factorial (int n);
int main(void){
    int n;
    cout<<"Enter a number, q to exit\n";
    while (cin>>n)
    {
        cout<<"enter a number: \n";
        cout<<factorial(n)<<endl;
    }                                    
    return 0;
}
int factorial (int n){
    int result;
    if (n==1)   
    {   
        result = 1;
    }else
    result = n*factorial(n-1);                                                                                                        

    return result;
    
}