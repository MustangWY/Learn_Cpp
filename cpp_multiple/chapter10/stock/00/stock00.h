#ifndef __STOCK00__H__
#define __STOCK00__H__
#include<string>
class Stock
{
private:
    std::string company;            //private中的成员只能通过public中的成员访问
    long shares;        //股票数量
    double share_val;   //单股价格
    double total_val;   
    void set_total(){total_val = shares*share_val;}    //定义在类声明中的函数自动转换为内联函数
                                                        //内联函数规则要求在每个使用它的文件中都对其进行定义
                                                        //简单方法是将内联函数定义放在头文件中
    /* data */
public:                     //使用类对象的程序只有通过public成员才能访问private成员
   
    void acqure( const std::string &co, long n, double pr );//获取某公司股票
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();

};
 
#endif