#include<iostream>
#include<cstdlib>

typedef int ElemType;
/*c表示法：c中使用结构体定义变量时要在结构体名称前面加struct，这里使用typedef给结构体取别名来省略struct。同时LinkList类指针即为指向单链表的头指针*/
typedef struct LNode
{   
    ElemType data;
    struct  LNode *next;

    
}LNode, *PNode;



typedef struct List{    //管理链表
    PNode First;
    PNode Last;
    size_t size;                //unsigned int类型，长度根据系统位数而定
}List;