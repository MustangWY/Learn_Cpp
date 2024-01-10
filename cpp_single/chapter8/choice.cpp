#include<iostream>
using namespace std;
template <typename T>
T lesser(T a , T b);
int lesser(int a, int b){ /////函数2
    a = a<0? -a:a;
    b = b<0? -b:b;
    return a<b?a:b;
    
}
int main(void){
    int m = 20;
    int n = -30;

    double x = 15.5;
    double y = 25.9;

    cout<<lesser(m,n)<<endl;//调用函数2
    cout<<lesser(x, y)<<endl; //调用函数1
    cout<<lesser<>(m,n)<<endl; //告诉编译器使用模板函数而不使用具体函数
    cout<<lesser<int>(x,y)<<endl; //使用模板函数，并且将使用int类型，强制转换
    return 0;
}

template <typename T>//函数1
T lesser(T a , T b){
    return a<b? a:b;
}
