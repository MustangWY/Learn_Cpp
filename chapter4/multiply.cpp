#include <iostream>
using namespace std;
int main(void){
    int i,j;
    for ( i = 1; i < 10; i++)
    {   
        for (j = 1; j <= i; j++)
        {   
            int k;
            k=i*j;
            
                cout<<i<<'*'<<j<<'='<<k<<'\t';
            
            
            
        };
    
        cout<<'\n';
    }
    return 0;
    
}