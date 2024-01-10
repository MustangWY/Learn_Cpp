#include<iostream>
using namespace std;
struct abc
{
    int a;
    int b;
    char c[4];
};

int main(void){

    abc* pt = new abc[3];
    pt[1].a;
    (pt+1)->a;
    const char *pd = "taco";
    cout<<pd[2];
    (&(pt[1]))->a = 3;
    cout<<pt<<endl;
    cout<<&(pt[0])<<endl;
    cout<<pt[0].a<<endl;
    cout<<(pt+1)->a<<endl;
    cout<<(&(pt[1]))->a<<endl;
    cout<<&pt<<endl;
    return 0;
}