#include<iostream>
#include<string>
#include"golf.h"
using namespace std;
void setgolf(golf &g, const string name, int hc){
    g.handicap = hc;
    int i = 0;
    g.fullname = name;
}
int setgolf(golf &g){
    
    int dtemp;
    string ntemp;
    cout<<"Please enter your name: \n";
    getline(cin,ntemp);
    if (!ntemp[0])
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
     
    setgolf(g,ntemp,dtemp);
    return 1;
    
}
void handicap(golf & g, int hc){
    g.handicap = hc;
}
void showgolf(const golf & g){
    cout<<g.fullname<<" : "<<g.handicap<<endl;
}