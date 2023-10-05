#include<iostream>
using namespace std;
int main(void){
    int i,j;
    cout<<"Please enter two numbers, the smaller one first: ";
    cin>>i;
    cout<<"Now enter the second one: ";
    cin>>j;
    int diff = j - i;
    int sum = 0;
    for ( i ; i <=j; i++)
    {
        sum+=i;
        /* code */
    }
    cout<<"Here is the outcome:"<<sum;
    

    return 0;
}