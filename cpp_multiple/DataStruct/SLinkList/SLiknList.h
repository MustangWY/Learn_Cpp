#ifndef ___SLIST___
#define ___SLIST___
#define Size 20
#include<iostream>

typedef int ElemType;

typedef struct LNode
{   
    ElemType data;
    int cur;
    /* data */
}LNode, *Node;




class SLinkList{
    private:
    Node head;
    Node pool;
    int length;
    public:
        SLinkList();
        int Malloc_SL();
        void push_front(ElemType e);
        void ShowSlist() const;
        void Free_SL(int k);
        bool DeleteList_SL(int k);
        void push_back(ElemType e);
        void pop_back(ElemType &e);
        void pop_front(ElemType &e);
        void insert_pos(ElemType e, int pos);
        void GetElem(ElemType &e, int pos);
        ~SLinkList();
};




#endif