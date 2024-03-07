#include <iostream>
#define MAXSIZE 20   
//#define ElemType int
typedef int ElemType;

typedef struct 
{   
    ElemType data;
    int cur;
    /* data */
}component, SLinkList[MAXSIZE];     //typedef为数组定义简洁的类型名称，这里声明SLinklist类型就等于声明component[MAXSIZE]

void initSpace_SL(SLinkList &space);
int Malloc_SL(SLinkList &space);
void addSList(SLinkList &space, ElemType e);
void ShowSlist(const SLinkList &space);
void Free_SL(SLinkList &space, int k);
bool DeleteList_SL(SLinkList &space, int k);
void initSpace_SL(SLinkList &space){

    for (int i = 1; i < MAXSIZE-1; i++)//初始化space，将space里第二个元素以后每一个元素的cur指定为下一个元素的位置，space[0].cur为头指针，0表示空指针
                                        //这里将space[0]作为数据链表的头指针，space[1]作为备用链表的头指针，并且数据链表以-1表示表尾
    {   
        space[i].cur = i+1;
        /* code */
    }
    space[MAXSIZE-1].cur = 0;
    space[0].cur = -1;
}

int Malloc_SL(SLinkList &space){
    int i = space[1].cur;
    if (space[1].cur)
    {   
        space[1].cur = space[i].cur;
        /* code */
    }else return 0;

    return i;
    

}

void ShowSlist(const SLinkList &space){
    int i = space[0].cur;
    while (i!=-1)
    {   
        std::cout<<"Elem:"<<space[i].data<<std::endl;
        i = space[i].cur;
        /* code */
    }
    
}
void addSList(SLinkList &space, ElemType e){
    int i =Malloc_SL(space);
    if (!i)
    {   
        std::cout<<"Allocation failed.\n";
        return;
        /* code */
    }
    space[i].data = e;
    if (space[0].cur == -1)
    {   
        space[i].cur = -1;

        /* code */
    }else{
        space[i].cur = space[0].cur;
    
    }
    space[0].cur = i;
    
}

void Free_SL(SLinkList &space, int k){
    space[k].cur = space[1].cur;
    space[1].cur = k;                       //将第k个元素从数据链表删除，插入备用链表

}


bool DeleteList_SL(SLinkList &space, int k,ElemType &e){       
    int j = 0;
    int cur = space[0].cur;
    while ((j<k-1)&&(cur!=-1))
    {   
        cur = space[cur].cur;
        j++;
        /* code */
    }
    if (cur == -1)
    return false;
    component q =space[space[cur].cur];
    e = q.data;
    Free_SL(space,space[cur].cur);
    space[cur].cur = q.cur;
    return true;
    
}

int main(void){
    SLinkList sp;
    ElemType e;
    initSpace_SL(sp);
    addSList(sp,3);
    addSList(sp,4);
    addSList(sp,5);
    ShowSlist(sp);
    DeleteList_SL(sp,3,e);
    ShowSlist(sp);
    return 0;
}
