#include<iostream>
#include<new>
using namespace std;
int main(void){
    char buffer[10] = "abcdef";
    cout<<buffer<<endl;
    char *pt = new(buffer) char[12];
    cout<<pt<<endl;
    for (int i = 0; i < 12; i++)
    {   
        cout <<*pt<<' ';
        pt++;
        /* code */
    }
    
    return 0;
}