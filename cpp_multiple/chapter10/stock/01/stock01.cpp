#include<iostream>
#include"stock01.h"



Stock::Stock( const std::string &co, long n , double pr ){               //对类中成员函数给出定义时使用定义域解析运算符
    std::cout<<"Constructor using "<<co<<" called.\n";
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

/**Stock::Stock(){
 *          company = "Mo name";
 *          shares = 0;
 *          share_val = 0;
 *          total_val = 0.0;
}

没有参数的默认构造函数
**/
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

void Stock::show() const {          //const成员函数定义
    using std::cout;
    using std::ios_base;
    
    
    cout<<"Company: "<<company<<std::endl
             <<"Shares: $"<<shares<<std::endl
             <<"Shares Price: $"<<share_val<<std::endl;
             
    cout<<"Total Worth: $"<<total_val<<std::endl;
   
}

Stock::~Stock(){
}

const Stock& Stock::topval(const Stock & s) const{
    if (s.total_val>total_val)
    {   
        return s;   //参数对象
        /* code */
    }else
    return *this;//this指针，指向用来调用成员函数的对象（this被作为隐藏参数传递给方法）
                    //*this调用方法的对象
    

}
