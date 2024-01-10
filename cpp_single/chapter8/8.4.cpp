#include<iostream>
#include<cstring>

using namespace std;
struct stringy
{   
    char * str;
    int ct;
    /* data */
};
void set (stringy &str, char *pt);
void show(const stringy &str,int n =1);
void show(const char *str,int n =1);
int main(void){
    stringy beany;
    char testing [] = "Reality isn't what it used to be.";
    set(beany,testing);
    show(beany);
    show(beany,2);
    testing[0] = 'D';
    testing [1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done !");

    return 0;
}
void set (stringy &str, char *pt){
    int length = strlen(pt);
    char * cp = new char [length];
    int i = 0;
    while (pt[i])
    {   
        cp[i] = pt[i];
        i++;
        /* code */
    }
    cp[i] = pt[i];
    str.str = cp;
    str.ct = i-1;
}

void show(const stringy &str,int n ){
    for (int  i = 0; i < n; i++)
    {
        cout<<str.str<<endl;
        /* code */
    }
    

}

void show(const char *str,int n ){
    for (int i = 0; i < n; i++)
    {   
        cout<<str<<endl;
        /* code */
    }
    

}

