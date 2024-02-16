#include<iostream>
#include"stock01.h"
const int STKS = 4;
int main(void){
    using std::cout;
    Stock food = Stock{"World cabbage", 250, 1.25};  //显式调用构造函数
    Stock garment("Furry Mason", 50,2.5); //隐式调用构造函数
    food.show();                           //等价于Stock garment = Stock{"Furry Mason", 50,2.5};
    garment.show();
    Stock *pstock = new Stock("Electroshock Games", 18, 19.0); //每次创建对象都使用构造器，与new关键字一起使用
                                                                  //创建并初始化一个对象，并将对象地址赋值给pstock
    //此时不能在使用Stock stock1;这样的语句，因为给出构造函数之后，编译器不在给出默认构造函数，这将导致前面声明出错。
    //可以使用函数重载重新给出没有参数的构造函数，同时给成员提供隐式的初始值，或者给构造函数参数全部给出默认值，不要同时使用两种方式
    Stock stock1;       //此时相当于调用构造函数但是不传参数
    stock1.show();
    (*pstock).show();
    delete pstock;

    {
    cout<<"********************************************************\n";

    cout<<"Using constructors to create new objects\n";
    Stock stock2("NanoSmart", 12,20.0);
    stock2.show();
    Stock stock3("Boffo Objects", 2, 2.0);
    stock3.show();


    cout<<"Assigning stock2 to stock3: \n";
    stock3 = stock2;
    cout<<"Listing stock2 and stock 3 \n";
    stock2.show();
    stock3.show();


    cout<<"Using a constructor to reset an object:\n";          //stock1已经存在，程序将创建一个新的临时的对象，然后将其内容赋值给stock1，随后编译器调用析构函数删除该临时对象
    stock1 = Stock("Nifty Foods", 10 ,20.0);
    cout<<"Revised stock1: \n";
    stock1.show();
    cout<<"Done.\n";
    }
    cout<<"***********************************************************\n";

    Stock stocks[STKS] = {
       Stock("NanoSmart", 12,20.0),
       Stock("Boffo Objects", 200, 2.0),
       Stock("Monolithic Obelisks", 130, 3.25),
       Stock("Fleep Enterprises", 60,6.5)
    };          //使用构造函数初始化对象数组，必须为每个元素调用构造函数，如果在括号中不声明对象，则调用默认构造函数进行构造。
                //要创建对象数组，必须要有默认构造函数。

    cout<<"Stock holdings: \n";
    for (int i = 0; i < STKS; i++)
    {   
        stocks[i].show();
        /* code */
    }

    const Stock* top = &stocks[0];
    for (int i = 1; i < STKS; i++)
    {   
        top = &top->topval(stocks[i]);
        /* code */
    }
    cout<<"\nMost valuable holding:\n";
    (*top).show();

    return 0;
}