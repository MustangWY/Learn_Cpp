#include <iostream> 
#include <new>
#include <cstdlib>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW -1
typedef int ElemType;


typedef struct 
{   
    ElemType *elem;
    int length;
    int listsize;
    /* data */
}Sqlist;



void MergeList_Sq(Sqlist L1, Sqlist L2, Sqlist &L3);
int LocateElem_Sq(Sqlist L, ElemType e, int (*compare) (ElemType, ElemType));
int InitList_SQ(Sqlist &L);
int ListInsert_Sq(Sqlist &l, int i, ElemType e);
int ListDelete_Sq(Sqlist &L, int i, ElemType &e);
int IsEqual(ElemType, ElemType);
void UnionList_Sq(Sqlist &La, Sqlist &&Lb);
void ShowList(const Sqlist &L);

int InitList_SQ(Sqlist &L){
    L.elem = new ElemType [LIST_INIT_SIZE];
    if (!L.elem)
    {   
        exit(OVERFLOW);
        /* code */
    }

    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;

}

int ListInsert_Sq(Sqlist &l, int i, ElemType e){            //时间复杂度n/2
    if ((i<1)||(i>l.length+1))
    {   
        return 0;
        /* code */
    }
    if (l.length>=l.listsize){
        ElemType *newbase = new (l.elem)ElemType[LISTINCREMENT+l.listsize];
        if (!newbase)
        {   
            exit (OVERFLOW);
            /* code */
        }
        l.elem = newbase;
        l.listsize+=LISTINCREMENT;
        
    }   
    ElemType *q = &l.elem[i-1];
    ElemType *p = &l.elem[l.length-1];
    while (q<=p)
    {   
        *(p+1) = *p;
        p--;
        /* code */
    }               //指针p指向线性表末尾，指针q指向插入位置，只要指针p不等于指针q，那么p指向的后一个元素等于p指向的元素，全部元素向后挪，将p--得到下一个。
    
    *q = e;
    l.length++;
    return 1;
}

int ListDelete_Sq(Sqlist &L, int i, ElemType &e){           //时间复杂度：(n-1)/2
    if ((i<1)||(i>L.length+1))
    {   
        return 0;
        /* code */
    }
    ElemType *q = &L.elem[i-1];
    ElemType *p = &L.elem[L.length-1];
    e = L.elem[i-1];
    while (q<=p)
    {   
        *q = *(q+1);
        q++;                                //指针p指向线性表末尾，指针q指向删除位置，只要指针q不等于指针p，指针q指向的值就等于指针q指向的下一个位置的值
        /* code */
    }
    L.length--;
    return 1;
    

}


int IsEqual(ElemType e1, ElemType e2){
    return (e1 == e2);
}




int LocateElem_Sq(Sqlist L, ElemType e, int (*compare) (ElemType, ElemType)){
    int i = 0;
    for ( i ; i < L.length; i++)
    {   
        if (compare(L.elem[i],e))                   //函数名相当于函数指针，可以直接拿来用，如果线性表中的元素满足与元素e的compare关系，则停止循环，并且返回线性表中第一个满足的元素位置
        break;
        /* code */
    }
    if (i<L.length)
    {   
        return i+1;                                 
        /* code */
    }else return 0;
}




void MergeList_Sq(Sqlist L1, Sqlist L2, Sqlist &L3){
    InitList_SQ(L3);
    int i = 1,j = 1;
    int k = 0;
    while ((i<=L1.length)&&(j<=L2.length))
    {   
        if (L1.elem[i-1]>L2.elem[j-1])
        {   
            ListInsert_Sq(L3,++k,L2.elem[j-1]);
            j++;
            /* code */
        }else{
            ListInsert_Sq(L3,++k,L1.elem[i-1]);
            i++;
            }
        
        /* code */
    }
    while (i<=L1.length)
    {   
        ListInsert_Sq(L3,++k,L1.elem[i-1]);
        i++;
        /* code */
    }
     while (j<=L2.length)
    {   
        ListInsert_Sq(L3,++k,L2.elem[j-1]);
        j++;
        /* code */
    }


}

void UnionList_Sq(Sqlist &La, Sqlist &Lb){
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;
    int i = 0, j = 0;
    for ( i ; i < La.length; i++)
    {   
        for (j ; j < Lb.length; j++)
        {   
            if (!(*(pa+i) == *(pb+j)))              //将b表插入到a表后面，分别取出b表元素，与a表元素相比较，不同就将b表元素插入a表后面，相同不做操作。
                                                    //这里注意i和j的作用域
            {   
                ListInsert_Sq(La,La.length+1,*(pb+j)); 
            }
        }
    }
    

}
void ShowList(const Sqlist &L){
    for (int i = 0; i < L.length; i++)
    {   
        std::cout<<L.elem[i]<<std::endl;
        /* code */
    }

}

int main(void){
    Sqlist sq;
    ElemType e;
    InitList_SQ(sq);
    ListInsert_Sq(sq,1,20);
    ListInsert_Sq(sq,2,30);
    ListInsert_Sq(sq,3,40);
    std::cout<<"List: \n";
    for (int i = 0; i < 3; i++)
    {   
        std::cout<<*(sq.elem+i)<<std::endl;
        /* code */
    }
    int j = LocateElem_Sq(sq,40,IsEqual);
    std::cout<< "40 is in "<<j<<" place.\n";
    std::cout<<"After Delete: \n";
    
    ListDelete_Sq(sq,2,e);
    
    for (int i = 0; i < 2; i++)
    {   
        std::cout<<*(sq.elem+i)<<std::endl;
        /* code */
    }
    std::cout<<"Deleted member: "<<e<<std::endl;
    int k = LocateElem_Sq(sq,40,IsEqual);
    std::cout<< "40 is in "<<k<<" place.\n";
    Sqlist sqa;
    InitList_SQ(sqa);
    ListInsert_Sq(sqa,1,10);
    ListInsert_Sq(sqa,2,20);
    ListInsert_Sq(sqa,3,50);
    Sqlist sqb;
    MergeList_Sq(sq,sqa,sqb);
    ElemType *pt = sqb.elem;
    for (int i = 0; i < 5; i++)
    {   std::cout<<*pt<<"  ";
        pt++;
        /* code */
    }
    std::cout<<"\nLength of sqa: "<<sqa.length<<std::endl;
    std::cout<<"Length of sq: "<<sq.length<<std::endl;
    UnionList_Sq(sq,sqa);
    ShowList(sq);
    std::cout<<"Hello";
    return 0;
}