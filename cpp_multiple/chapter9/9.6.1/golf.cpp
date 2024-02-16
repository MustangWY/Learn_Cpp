#include<iostream>
#include"golf.h"
using namespace std;
void setgolf(golf &g, const char * name, int hc){
    g.handicap = hc;
    int i = 0;
    while (*name)
    {       
        g.fullname[i] = *name;
        if (i>Len)
        {   
            g.fullname[i-1] = '\0';
            break;
            /* code */
        }
        
        name++;
        i++;
    }  
}
int setgolf(golf &g){
    char temp[Len];
    int dtemp;
    cout<<"Please enter your name: \n";
    cin.getline(temp,Len);
    if (!temp[0])
    {   setgolf(g,"NA",0);
        return 0;
        /* code */
    }
    cout<<"Please enter your handicap level: \n";
    while (!(cin>>dtemp))
    {   
        cout<<"Please enter a number: \n";
        cin.clear();
        while (cin.get()!='\n')
        {   
            continue;
            /* code */
        }
        
        /* code */
    }
    cin.get();
     
    setgolf(g,temp,dtemp);
    return 1;
    
}
void handicap(golf & g, int hc){
    g.handicap = hc;
}
void showgolf(const golf & g){
    cout<<g.fullname<<" : "<<g.handicap<<endl;
}