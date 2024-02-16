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
   
    Stock( const std::string &co = "No name", long n = 0, double pr = 0.0);//构造函数，与类名一致，
   // Stock();      // 默认构造函数                                                     //没有声明返回值，用于构造新对象，将值赋给对象的数据成员  将所有参数都给上默认值也是定义默认构造函数的一种办法

    ~Stock();       //析构函数   对象过期时，程序调用该函数，完成清理工作。如果构造函数使用了new分配内存，析构函数就要包含delete来删除分配的内存。析构函数没有参数
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show () const;      //const成员函数，保证方法不修改调用对象，使得const对象可以使用该函数。
    const Stock& topval(const Stock & s) const;
};
 
#endif