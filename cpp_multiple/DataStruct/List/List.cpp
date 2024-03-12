#include <iostream>
#include "List.h"

void Sqlist::sort(){
    ElemType *p = elem;
    if (length == 0)
    {   
        std::cout<<"Empty list.\n";
        return;
        /* code */
    }
    bool flag = false;
    for (int i = 0; i < length-1; i++)
    {   
        for (int j = 0; j < length-1-i; j++)
        {   
            if (*p > *(p+1))
            {   
                flag = true;
                ElemType temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
            p++; 
        }
        if (!flag)   
           break;           //进行完一轮排序之后，判断本轮排序是否有元素交换。如果没有则列表已经有序，终止循环
        else
            flag = false;
        p = elem; //注意进行完一轮排序以后，将指针重新指向列表头

    }
}

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
    return flag;
    
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
        p++;
        /* code */
    }
    std::cout<<std::endl;
    
}

int Sqlist::ListInsert_Sq(int i, ElemType e){
    if (i<1||i>length)
    {   
        std::cout<<"Wrong position.\n";
        return 0;
        /* code */
    }
    ElemType *q = elem+i-1;
    ElemType *p = elem+length-1;            //注意这里是 -1指向表尾元素，不减指向表尾后面一个元素
    while (q<=p)
    {   
        *(p+1) = *p;
        p--;

        /* code */
    }
    *q = e;
    length++;
    return 1;
}

int Sqlist::ListDelete_Sq(int i, ElemType &e){
    if (i<1||i>length)
    {   
        std::cout<<"Wrong position.\n";
        return 0;
        /* code */
    }
    ElemType *q = elem+i;
    ElemType *p = elem+length-1;  
    while(q <= p){
        *(q - 1) = *q;
        q++;
    }
    length--;
    return 1;

}

int Sqlist::IsEqual(ElemType e1, ElemType e2){
    if (e1 == e2)   
        return 1;
    else 
        return 0;
}

int Sqlist::find(ElemType e){
    ElemType *p = elem;
    for (int i = 0; i < length; i++)
    {   
        if (*p == e)
        {   
            return i+1;
            /* code */
        }
        p++;
        /* code */
    }

    return 0;
    

}

int Sqlist::deleteVal(ElemType e){
    ElemType *p = elem;
    ElemType a;
    int i = 0;
    for ( i; i < length; i++)
    {   
        if (elem[i] == e)
        {   
            break;
        }
        /* code */
    }
    if (i >= length)
    {   
        std::cout<<"Value not exist.\n";
        return 0;
        /* code */
    }else{
        this->ListDelete_Sq(i+1,a);
        return 1;
    }
    return 0;
}

int Sqlist::Show_Length(){
    return this->length;
}
void Sqlist::reverse(){
    if (length == 0||length ==1)
    {   
        return;
        /* code */
    }
    ElemType *p = elem;
    for (int i = 0; i < length/2; i++)      //不管是奇数还是偶数交换次数都等于长度除以二
    {   
        ElemType temp = *(p+i);
        *(p+i) = *(p+length-1-i);                 
        *(p+length-1-i) = temp;
    }
}