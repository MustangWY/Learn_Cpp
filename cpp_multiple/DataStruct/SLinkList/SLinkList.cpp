#include "SLiknList.h"

SLinkList::SLinkList(){
    head = new LNode[Size];
    pool = &head[1];
    for (int i = 0; i < Size; i++)
    {   
        head[i].cur = i+1;
        /* code */
    }
    head->cur = -1;
    head[Size-1].cur = 0;
    
    length = 0 ;
}

int SLinkList::Malloc_SL(){
    int i = pool->cur;
    pool->cur = head[i].cur;
    return i;
}


void push_front(ElemType e){
    
}