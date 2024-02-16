#include<iostream>
#include"stock00.h"




void Stock::acqure(const std::string &co, long n, double pr ){               //对类中成员函数给出定义时使用定义域解析运算符
    company = co;                                                            //使成员具有类作用域，可以在别的类中定义同名方法
    if (n<0)
    {   
        std::cout<<"Number of shares cant be negative: "<<company
        <<"shares set to 0. \n";
        shares = 0;
        /* code */
    }else shares = n;

    share_val = pr;
    set_total();    //类中的成员函数可以直接调用类中的成员，无论private还是public
    
}

void Stock::buy(long num, double price){

    if (num<0)
    {   
        std::cout<<"Number of shares cant be negative: "
        <<"Transaction is abortrd. \n";
        
        /* code */
    }else {
            shares += num;
            share_val = price;
            set_total();

    }
}

void Stock::sell(long num, double price){
    if (num<0)
    {   
        std::cout<<"Number of shares cant be negative: "
        <<"Transaction is abortrd. \n";
        
        /* code */
    }else if (num>shares)
    {   
        std::cout<<"Insufficient shares. Transaction is aborted\n";
        /* code */
    }else
    {
        shares-=num;
        share_val = price;
        set_total();

    }

}

void Stock::update(double price){

    share_val = price;
    set_total();

}

void Stock::show(){
    std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);//设置以浮点数显示
    std::cout<<"Company: "<<company<<std::endl
             <<"Shares: $"<<shares<<std::endl
             <<"Shares Price: $"<<share_val<<std::endl
             <<"Total Worth: $"<<total_val<<std::endl;
}