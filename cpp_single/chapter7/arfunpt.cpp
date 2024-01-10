#include<iostream>
using namespace std;
const double* f1(const double *ar,int n);//函数返回数组内元素的地址,且不希望通过该指针修改它
const double* f2(const double ar[],int n);
const double* f3(const double ar[],int n);
int main (void){
    double av[3]={1112.3,1542.6,2227.9};
    //
    //p1:pointer to a function
    const double*(*p1)(const double *, int)=f1;//函数名就是函数在内存中的地址
    auto p2 = f2;//c++11 auto自动定义类型
    cout<<"using pointers to functions\n";
    cout<<"Adress     Value"<<endl;
    cout<<(*p1)(av,3)<<" : "<<*(*p1)(av,3)<<endl;              //(*p1)(av,3) == f1(av,3)返回第一个元素的地址
    cout<<p2(av,3)<<" : "<<*p2(av,3)<<endl;                    //p2(av,3) == f2(av,3) 返回第二个元素的地址
    //
    //pa is an array of pointers that points to a funct+ion
    cout<<"using an array of pointers to functions(pa)\n";
    const double* (*pa[3])(const double *,int n) = {f1,f2,f3};
    auto pb = pa;//const double* (**pb)(const double* ,int)=pa;

    for ( int i = 0; i < 3; i++)
    {   
        cout<<pa[i](av,3)<<" : "<<*pa[i](av,3)<<endl;//pa是一组指向函数的指针，则pa[i]即其中元素就是一个指向函数的指针，可以直接括号调用
        /* code */
    }
    cout<<"using a pointer to a pointer to a function(pb)\n";
    for ( int i = 0; i < 3; i++)
    {   
        cout<<pb[i](av,3)<<" : "<<*pb[i](av,3)<<endl;//pb是一组指向函数的指针，则pb[i]即其中元素就是一个指向函数的指针，可以直接括号调用
        /* code */
    }
    //pc(pd) is a pointer to an array of function pointers 
    auto pc = &pa;//原本为：const double*(*(*pc)[3])(const double* int)=&pa;
    const double *(*(*pd)[3])(const double* ,int) = &pa;
    cout<<"using a pointer to an array of function pointrs\n";
    cout<<(*pc)[0](av,3)<<" : "<<*(*pc)[0](av,3)<<endl;  //(*pc) == pa-->(*pc)[0](av,3) == pa[0](av,3) == f1(av,3)
    const double *pdb = (*pd)[1](av,3);
    cout<<pdb<<" : "<<*pdb<<endl;                        //(*pd) == pa-->(*pc)[1](av,3) == pa[1](av,3) == f2(av,3)
    cout<<(*pd)[2](av,3)<<" : "<<*(*pd)[2](av,3);
    //cout<<（*(*pd)[2]）(av,3) 书p203
    return 0;
}
const double* f1(const double *ar,int n){
    return ar;
}
const double* f2(const double ar[],int n)
{
    return ar+1;
}
const double* f3(const double ar[],int n){
    return ar+2;
}