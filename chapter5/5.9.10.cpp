#include<iostream>
using namespace std;
int main (void){
    cout<<"Enter number of rolls: ";
    int roll = 0;
    cin>>roll;
    for (int i = 1; i <= roll; i++)
    {
        for (int j = roll-i; j >= 0; j--)
        {
            cout<<".";
        }
        for (int z=1; z <= i; z++)
        {
            cout<<'*';
            /* code */
        }
        cout<<'\n';
        
        /* code */
    }
    
    return 0;
}