#include"stack.h"
#include<iostream>
Stack::Stack(){
    top = 0;
    total = 0;
}
bool Stack::isempty() const{

    return top == 0;
}

bool Stack::isfull() const{

    return top == Max;
}

bool Stack::push(const Item& item){
    if (top<Max)
    {   
        items[top++] = item;
        return true;
        /* code */
    }
    else return false;

}

bool Stack::pop(Item &item){
    if (top>0)
    {   
        item = items[--top];    //top指向栈内下一个元素，弹出要弹top指向的前一个元素
        total+=item.payment;
        showTotal();        
        return true;
        /* code */
    }
    else return false;

}

void Stack::showTotal() const{
    std::cout<<"Total payment is: "<<total<<std::endl;
}