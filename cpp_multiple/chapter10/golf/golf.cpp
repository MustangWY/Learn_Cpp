#include<iostream>
#include"golf.h"

golf::golf(const char* name, int hc){
    handicap = hc;
    int i = 0;
    while (*name)
    {   
        fullname[i] = *name;
        if (i>Length)
        {   
            fullname[i-1] = '\0';
            break;
            /* code */
        }
        name++;
        i++;
        /* code */
    }
    

}

void golf::setgolf(){
    using std::cout;
    using std::cin;
    char tempname[Length];
    int temph;
    cout<<"Please enter your name: \n";
    cin.getline(tempname,Length);
    if (tempname[0] != '\0')
    {
        cout<<"Please enter handicap \n";
        while (!(cin>>temph))
        {   
            cout<<"Please enter a number:\n";
            cin.clear();
            while (cin.get()!='\n')
                continue;
            
        }
        
        
    }
    cin.get();
    *this = golf(tempname, temph);
}


void golf::ShowGolf() const{
    std::cout<<fullname<<" : "<<handicap<<std::endl;
}

void golf::SetHandicap(int hc){
    handicap = hc;
}