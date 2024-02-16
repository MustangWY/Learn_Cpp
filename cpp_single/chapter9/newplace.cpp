#include<iostream>
#include<new>
using namespace std;
const int BUF = 512;
const int N = 5;
char buffer[BUF];
int main(void){
    double *pd1,*pd2;
    int i;
    cout<<"Calling new ande placement new: "<<endl;
    pd1 = new double[N];
    pd2 = new(buffer) double [N];
    for ( i = 0; i < N; i++)
    {   
        pd2[i] = pd1[i] = 1000+20.0*i;

        /* code */
    }
    cout<<"memory address: \n"<<"heap: ";
    cout<<pd1<<" , buffer = "<<(void * )buffer<<endl;//void*是万能指针，这里buffer是char类型，直接使用输出会打印字符串。
    cout<<"Memory contents:\nj";
    for ( i = 0; i < N; i++)
    {   
        cout<<pd1[i] << " at " << &pd1[i] << " ; ";
        cout<<pd2[i] << " at " << &pd2[i] <<endl;

        /* code */
    }
    

    cout<<"calling new and placement new a second time: \n";
    double* pd3,*pd4;
    pd3 = new double[N];    //开辟新地址
    pd4 = new (buffer) double[N]; //重新写入数据
    for ( i = 0; i < N; i++)
    {   
        pd4[i] = pd3[i] = 1000 + 40.0*i;
        /* code */
    }
    cout<<"Memory contents: \n";
    for ( i = 0; i < N; i++)
    {   
        cout<<pd3[i] << " at " << &pd3[i] << " ; ";
        cout<<pd4[i] << " at " << &pd4[i] <<endl;

        /* code */
    }

    cout<<"\nCalling new and placement new a third time: \n";
    delete [] pd1;
    pd1 = new double [N];
    pd2 = new (buffer + N*sizeof(double)) double [N] ;//在buffer数组之后偏移40bytes的位置分配新的内存。

    for ( i = 0; i < N; i++)
    {   
        pd2[i] = pd1[i] = 1000+60.0*i;

        /* code */
    }
    for ( i = 0; i < N; i++)
    {   
        cout<<pd1[i] << " at " << &pd1[i] << " ; ";
        cout<<pd2[i] << " at " << &pd2[i] <<endl;

        /* code */
    }
    
    delete [] pd1;
    delete [] pd3;
    //pd2和pd4指向的是buffer，而buffer是指向静态内存的指针，delete只能用于指向常规new运算符分配的堆内存
    return 0;
}