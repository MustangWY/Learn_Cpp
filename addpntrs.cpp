#include<iostream>
int main(){
    using namespace std;
    double wages[3]={10000.0,20000.0,30000.0};
    short stacks[3]={3,2,1};
    //int arr [3];arr[3]={1,2,3};not allow,array must be initialized when created. 
    int *pa = new int[5];
    pa[0]=1;//new出来的数组可以在程序执行的时候进行初始化并决定长度,可以输入数组大小
    double* pw = wages;
    short* ps=&stacks[0];
    cout<<"pw = "<<pw<<", *pw = "<<*pw<<endl;
    cout<<"add 1 to pw:"<<endl;
    pw=pw+1;
    cout<<"pw = "<<pw<<", *pw = "<<*pw<<endl;
    cout<<"ps = "<<ps<<", *ps = "<<*ps<<endl;
    cout<<"add 1 to ps:"<<endl;
    ps=ps+1;
    cout<<"ps = "<<ps<<", *ps = "<<*ps<<endl;
    cout<<"pa = "<<pa<<", *pa = "<<*pa<<endl;
    delete [] pa;
    cout<<"access two elements with array nonations\n";
    cout<<"stacks[0] = "<<stacks[0]<<", stacks[1] = "<<stacks[1]<<endl;
    cout<<"access two elements with pointer nonations\n";
    cout<<"*stacks = "<<*stacks<<", *(stacks+1) = "<<*(stacks+1)<<endl;
    cout<<sizeof(wages)<<"size of wages array"<<endl;
    cout<<sizeof(pw)<<" size of pw pointer"<<endl;
    cout<<&stacks<<endl;
    cout<<stacks;
    return 0;
}