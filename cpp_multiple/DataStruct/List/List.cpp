#include <iostream>
#include "List.h"

Sqlist::Sqlist(){
    elem = new ElemType [LIST_INIT_SIZE];
    if (!elem)
    {   
        exit(OVERFLOW);
        /* code */
    }

    length = 0;
    listsize = LIST_INIT_SIZE;
}

int Sqlist::push_back(ElemType e){
    int flag = 0;
    if(length >= listsize){
        ElemType* newbase = new(elem)ElemType[listsize+LISTINCREMENT];
        if (!newbase)
        {   
            std::cout<<"LIST full, unable to allocate new memory.\n";
            return flag;
            /* code */
        }
        elem = newbase;
        listsize+=LISTINCREMENT;
        std::cout<<"List full, new memory allocated\n";
    }
    ElemType *p = elem;
    *(elem+length) = e;
    length++;
    flag = 1;
    return flag;
    
    }

int Sqlist::push_front(ElemType e){
    int flag = 0;
    if (length >= listsize)
    {
        ElemType *newbase = new(elem)ElemType[listsize+LISTINCREMENT];
        if (!newbase)
        {   
            std::cout<<"List full, unable to allocate new memory.\n";
            return flag;
            /* code */
        }
        std::cout<<"List full, new memory allocated.\n";
        elem = newbase;
        listsize+=LISTINCREMENT;
        /* code */
    }
    ElemType *p = elem+length;
    while (p >= elem)
    {   
        *(p+1) = *p;
        p--;
        /* code */
    }
    *elem = e;
    length++;
    flag = 1;
    return flag;
}

int Sqlist::pop_back(ElemType &e){
    int flag = 0;
    if (length == 0)
    {   
        std::cout<<"Empty list.\n";
        return flag;
        /* code */
    }
    *(elem+length-1) = e;
    length--;
    
}

int Sqlist::pop_front(ElemType &e){
    int flag = 0;
    if (length == 0)
    {   
        std::cout<<"Empty list.\n";
        return flag;
        /* code */
    }
    ElemType *p = elem+1;
    for (int i = 0; i < length; i++)
    {   
        *(p-1) = *p;
        p++;
        /* code */
    }
    length--;
    flag = 1;
    return flag;

}

void Sqlist::ShowList(){
    ElemType *p = elem;
    while (p<(elem+length))
    {   
        std::cout<<*p<<' ';
        /* code */
    }
    std::cout<<std::endl;
    
}

