#include<iostream>
#include"golf.h"
using namespace std;
int main(void){
    golf ca[3]={};
    for (int i = 0; i < 3; i++)
    {   
        int flag = 1;
        flag = setgolf(ca[i]);
        if (!flag)
        {   
            cout<<"Empty name, ending....... \n";
            for (int j = i+1; j < 3; j++)
            {   
                setgolf(ca[j],"NA",0);
                
            }
            break;
            
        }
        
        
    }
    for (int i = 0; i < 3; i++)
    {   
        showgolf(ca[i]);
        
    }

    
    golf ann;
    setgolf(ann);
    showgolf(ann);
    return 0;
}