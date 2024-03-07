#include<iostream>
using namespace std;
int main(void){
    int feet = 0, total = 0;
    cin>>feet;
    cin.get();
    cin>>total;
    int i = 1;
    for (i; i < total; i++)
    {   
        if (i*2+(total-i)*4 == feet)
        {   
            break;
            /* code */
        }
        
        /* code */
    }
    cout<<i<<endl;
    cout<<total-i;


}