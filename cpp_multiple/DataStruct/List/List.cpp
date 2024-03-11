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

int Sqlist::pop_back(ElemType &e){
    
    }
