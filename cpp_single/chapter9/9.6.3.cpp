#include<iostream>
#include<cstring>
#include<new>
using namespace std;
const int BUF = 512;

struct chaff{
    char dross[20];
    int slag;
};
char *pt = new char[BUF];//delete只能删除指向常规new运算分配的内存，不能删除指向静态内存的指针
int main(void){
    chaff * pd = new(pt) chaff [2];
    chaff *ps = pd;
    char temp[20];
    for (int i = 0; i < 2; i++)
    {   
        cout<<"Enter dross: \n";
        cin.getline(temp,20);
        strcpy(pd->dross,temp);
        cout<<"Enter slag: \n";
        while (!(cin>>pd->slag))
        {
            cout<<"Bad input, enter a number:\n";
            cin.clear();
            while (cin.get()!='\0')
                continue;
            /* code */
        }
        cin.get();
        pd++;
        /* code */
    }
    for (int i = 0; i < 2; i++)
    {   
        cout<<"dross: "<<ps->dross<<endl;
        cout<<"Slag: "<<ps->slag<<endl;
        ps++;
        /* code */
    }
    
    return 0;
}