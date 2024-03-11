#include<iostream>
#include<cstdlib>

typedef int ElemType;
/*c表示法：c中使用结构体定义变量时要在结构体名称前面加struct，这里使用typedef给结构体取别名来省略struct。同时LinkList类指针即为指向单链表的头指针*/
typedef struct LNode
{   
    ElemType data;
    struct  LNode *next;

    
}LNode, *LinkList;



/*  c++表示法：
typedef struct LNode
{   
    ElemType data;
    LNode *next;
    
} *LinkList;

*/


bool GetElem(LinkList L, int i, ElemType &e);
bool ListInsert_L(LinkList &L, int i, ElemType);
bool ListDelete_L(LinkList &L, int i, ElemType &e);
void CreateList_L_Reserved(LinkList &L, int n);
void CreateList_L_Sequential(LinkList &L, int n);
void ShowLinkList(const LinkList &l);
void MergList_L(LinkList &La,LinkList &Lb,LinkList &Lc);




LinkList InitLinkList(){
    LNode* L = (LinkList)new(LNode);
    if (L == NULL)
    {   
        exit(0);
        /* code */
    }
    L->next = NULL;
    return L;
}

bool GetElem(LinkList L, int i, ElemType &e){               //寻找单链表中的第i个元素
    LinkList p = L->next;
    int j = 1;                  //初始化，此时p指向第一个节点，j为计数器，为指向第几个节点
    while (p&&j<i)
    {   
        p = p->next;            //顺着指针往下查找，直到找到第i个节点或者遇到空指针（到达链表末尾）
        j++;
        /* code */
    }
    if (!p||j>i)
    return false;
    e = p->data;
    return true;
}

bool ListInsert_L(LinkList &L, int i, ElemType e){
    LinkList p = L;
    int j = 0;
    while (p&&j<i-1)            //找到第i个元素的前一个元素，将添加的元素的指针指向原先第i个元素指针指向的元素，然后将第i-1个元素指针指针指向添加的元素，
    {   
        p = p->next;
        j++;
    }
    if (!p||j>i-1)
    return false;
    LinkList s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;

    
}

bool ListDelete_L(LinkList &L, int i, ElemType &e){
    LinkList p = L;
    int j = 0;
    while (p&&j<i-1)
    {   
        p=p->next;
        j++;
    }
    if (!(p->next)||j>i-1) return false;
    e = p->data;
    LinkList q = p->next;
    p->next = q->next;
    delete q;
    return true;
}



void CreateList_L_Reserved(LinkList &L, int n){       //时间复杂度：O(n)//逆序创建
    L = (LinkList)new LNode;
    L->next = NULL;
    for (int i = n; i >0 ; --i)
    {   
        LinkList p = (LinkList)new LNode;       //创建头节点
        std::cout<<"Please enter an element: \n";
        while (!(std::cin>>p->data))                //获取元素
        {   
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout<<"Please enter a number: \n";
            
        }
        std::cin.get();     
        p->next = L->next;      //插入到表头 逆序
        L->next = p;                
        /* code */
    }
    



}

void CreateList_L_Sequential(LinkList &L, int n){               //顺序创建//时间复杂度：O(n)
    L =(LinkList) new LNode;
    L->next = NULL;
    LNode* q = L;
    for (int i = 1; i <= n; i++)
    {   
        LinkList p = (LinkList) new(LNode);
        std::cout<<"Please enter an element: \n";
        while (!(std::cin>>p->data))                //获取元素
        {   
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout<<"Please enter a number: \n";
            
        }
        std::cin.get(); 
        
        p->next = NULL;         //顺序创建，使用临时指针q来指向前一个元素
        q->next = p;
        q = p;
    }
    

}

void ShowLinkList(const LinkList &l){
    LinkList p = l->next;
    int i = 1;
    while (p)
    {   
        std::cout<<"Element "<<i<<": "<<p->data<<std::endl;
        p = p->next;            //不是线性表，往下遍历使用指针往下遍历，不能简单的将指针加一
        i++;
        /* code */
    }
    

}

void MergList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
    LinkList pa,pb,pc;
    pa = La->next;          //pa,pb分别指向要比较的元素（非头节点）
    pb = Lb->next;
    Lc = pc = La;           //pc指向a链表的头节点，这里使用a链表的头节点当作c链表的头节点
    while (pa&&pb)
    {   
        if (pa->data<=pb->data)     //如果pa的元素大于pb的元素
        {   
            pc->next = pa;          //将pa所指元素连接到pc所指元素之后
            pc = pa;                //将pc等于pa，相当于pc链表往后移一个元素
            pa = pa->next;         
            /* code */
        }else{
            pc->next = pb;
            pc = pb;            //将pb所指元素连接到pc所指元素之后
            pb = pb->next;
            }
        /* code */
    }

    pc->next = pa?pa:pb;        //上面将la,lb链表相同数目部分连接完毕，只要看pa，pb指针哪个后面还有元素，将pc直接连接还有元素的指针就行
    delete Lb;

}


int main(void){
    using namespace std;
    LinkList l = InitLinkList();
    CreateList_L_Reserved(l,3);
    cout<<"l1:"<<(l->next)->data<<endl;
    cout<<"l2:"<<((l->next)->next)->data<<endl;
    LinkList a;
    CreateList_L_Sequential(a,3);
    ShowLinkList(a);

    return 0;
}
