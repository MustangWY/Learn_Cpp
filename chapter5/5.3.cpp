#include<iostream>
using namespace std;
int main(void){
    int x;
    cout<<"The expression x = 100 has the value ";
    cout<<(x=100)<<endl;//cout<<x=100<<endl这里<<运算符优先级高，cout先于x结合需要用括号括起来
    cout<<"The expression x<3 has the value ";
    cout<<(x<3)<<endl;
    cout<<"The expression x>3 has the value ";
    cout<<(x>3)<<endl;
    cout.setf(ios_base::boolalpha);
    cout<<"The expression x<3 has the value ";
    cout<<(x<3)<<endl;
    cout<<"The expression x>3 has the value ";
    cout<<(x>3)<<endl;
    return 0;
}
