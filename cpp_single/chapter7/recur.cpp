#include<iostream>
using namespace std;
void countdown(int n);
int main(){
    countdown(5);
    return 0;
}


void countdown(int n){
    cout<<"Counting down ..."<<n<<" n( at"<<&n<<")"<<endl;//每个递归都创建自己的一套变量
    if (n>0)
    {
        countdown(n-1);
    }
    cout<<n<<": kaboom!"<<" n( at"<<&n<<")"<<endl;


}