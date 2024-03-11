#ifndef ___LIST___
#define ___LIST___
#include <iostream> 
#include <new>
#include <cstdlib>
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10
#define OVERFLOW -1
typedef int ElemType;

class Sqlist
{
private:
    ElemType *elem;
    int length;
    int listsize;
    
public:
    Sqlist();
    void MergeList_Sq(Sqlist L1, Sqlist L2, Sqlist &L3);
    int LocateElem_Sq(Sqlist L, ElemType e, int (*compare) (ElemType, ElemType));
    int ListInsert_Sq(Sqlist &l, int i, ElemType e);
    int ListDelete_Sq(Sqlist &L, int i, ElemType &e);
    int IsEqual(ElemType, ElemType);
    void UnionList_Sq(Sqlist &La, Sqlist &&Lb);
    void ShowList();
    int push_back(ElemType);
    int push_front(ElemType e);
    int pop_back(ElemType &e);
    int pop_front(ElemType &e);
    int find(Sqlist &l, ElemType e);
    int Show_Length(Sqlist);
    ~Sqlist();

};


#endif