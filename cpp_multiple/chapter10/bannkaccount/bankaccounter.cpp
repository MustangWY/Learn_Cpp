#include<iostream>
#include"bankaccount.h"
#include<cstring>
bankaccount::bankaccount(const char *pn ,  const char * pa , double m ){
    using namespace std;
    strcpy(name,pn);
    strcpy(acc,pa);
    if (m<0)
    {   
        cout<<"Number of deposit cant be negative. Set deposit to zero.\n";
        money = 0;
        /* code */
    }else money = m;
    

}


void bankaccount::showAccount() const{
    using namespace std;
    cout<<"Name: "<<name<<endl;
    cout<<"Account number: "<<acc<<endl;
    cout<<"Deposit: "<<money<<endl;

}

void bankaccount::deposit(double m){
    if (m<0)
    {   
        std::cout<<"Number of deposit cant be negative. Deposit failed.\n";

        /* code */
    }else{

        money += m;
        std::cout<<"Deposit successeful.\n";
    }
    

}

void bankaccount::withdraw(double m){

    if (money < m)
    {   
        std::cout<<"Insufficient funds.\n";
        /* code */
    }else if (m<0)
    {   
        std::cout<<"Number of withdraw cant be negative. Withdraw failed. \n";
        /* code */
    }else{
        money -= m;
        std::cout<<"Withdraw successful.\n";
    }
    
    
}


bankaccount:: ~bankaccount(){};