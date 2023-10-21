#include <iostream>
using namespace std;
const int MAX = 5;
int main (void){
    int golf[MAX];
    cout<<"Please enter your golf score\n";
    cout<<"you must enter 5 rounds\n";
    int i;
    for ( i = 0; i < MAX; i++)
    {
        cout<<"round #"<<i+1<<"： ";
        while (!(cin>>golf[i]))
        {
            cin.clear();//reset cin
            while(cin.get()!='\n'){
                continue;//get rid of bad input
            }
            cout<<"Please enter a number: ";
        }
        
        /* code */
    }
    double total = 0.0;
    for ( i = 0; i < MAX; i++)
    {
        total+=golf[i];
    }
    cout<<total/MAX<<" = AVERGE SCORE "<<MAX<<" rounds ";
    
    
    return 0;
}