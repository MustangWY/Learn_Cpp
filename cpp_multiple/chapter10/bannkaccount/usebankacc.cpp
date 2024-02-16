#include<iostream>
#include"bankaccount.h"

using namespace std;

int main(void){
    bankaccount Abby;           //隐式使用默认构造函数不能带括号
    bankaccount Mike("Mike", "612544785", 100000.1);
    Abby.showAccount();
    Mike.showAccount();
    cout<<"Depositing 10000 to Mike.\n";
    Mike.deposit(10000.111);
    Mike.showAccount();
    cout<<"Withdrawing 200000 from Mike.\n";
    Mike.withdraw(200000);
    Mike.showAccount();
    bankaccount Jack("Jack", "6215556733", -3000);
    Jack.showAccount();
    return 0;
}