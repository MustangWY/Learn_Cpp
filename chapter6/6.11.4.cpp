#include<iostream>
const int strsize = 50;
using namespace std;
struct bop
{   
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
    /* data */
};

int main(void){
    char ch;
    bop member[5]={
        {
            "Wimp Macho",
            "Junior Programmer",
            "MIPS",
            1
        },
        {
            "Raki Rhodes",
            "Junior Programmer",
            "MIPSs",
            2
        },{
            "Celia Laiter",
            "Junior Programmer",
            "MIPS",
            3
        },{
            "Hoppy Hipman",
            "Analyst Trainee",
            "MIPS",
            2
        },{
            "Pat Hand",
            "Doctor",
            "LOOPY",
            3
        },
    };

    std::cout<<"Benevolent Order of Programmers Report"<<endl;
    std::cout<<"a.display by name \t"<<"b.display by title"<<endl;
    std::cout<<"c.display by bopname \t"<<"d.display by preference "<<endl;
    std::cout<<"q.quit"<<endl;
    cin>>ch; 
    while (ch!='q')
    {
        
        switch (ch)
        {
            case 'a': 
                for (int i = 0; i < 5; i++)
                {
                    cout<<member[i].fullname<<endl;
                }
        
            break;
            case 'b': 
                for (int i = 0; i < 5; i++)
                {
                    cout<<member[i].title<<endl;
                }
            break;
            case 'c':
                for (int i = 0; i < 5; i++)
                {
                    cout<<member[i].bopname<<endl;
                }
            break;
            case 'd':
                for (int i = 0; i < 5; i++)
                {   
                    if (member[i].preference==1)
                    {
                        cout<<member[i].fullname<<endl;
                    }else if (member[i].preference==2)
                    {
                        cout<<member[i].title<<endl;
                    }else if (member[i].preference==3)
                    {
                        cout<<member[i].bopname<<endl;
                    }                   
                }   
            break;
            default:cout<<"That's not an option,please enter again."<<endl;
            break;
    }
    cout<<"Next choice: ";
    cin>>ch;
    }
    return 0;
}