#include<iostream>
using namespace std;

typedef struct {
    char ch;
    bool flag;
}chs;
chs* generate();

chs* generate(){
    chs *p = new chs[26];
    char temp = 'A';
    for (int i = 0; i < 26; i++)
    {
        p->ch = temp;
        temp++;
        /* code */
    }
    
}

int main(void){


    return 0;
}