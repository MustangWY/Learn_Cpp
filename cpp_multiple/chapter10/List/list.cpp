#include"list.h"
#include<iostream>
List::List(){
    top = 0;
}
bool List::isempty() const{

    return top == 0;
}

bool List::isfull() const{

    return top == Max;
}

bool List::Add (const Item& item){
    if (top<Max)
    {   
        items[top++] = item;
        return true;
        /* code */
    }
    else return false;

}

void List::visit(void (*pf)(Item& )){

    for (int i = 0; i < top; i++)
    {   
        pf(items[i]);               //在visit函数里面调用pf指向的函数，这里将item数组的成员传给pf
        /* code */
    }
    

}
void visit_Item ( Item & item){
    std::cout<<"Item: "<<item<<std::endl;
}