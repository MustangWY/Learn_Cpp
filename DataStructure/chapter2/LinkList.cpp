#include<iostream>
#include<cstdlib>

/*
    单链表的实现
*/

typedef int ElemType;
/*c表示法：c中使用结构体定义变量时要在结构体名称前面加struct，这里使用typedef给结构体取别名来省略struct。同时LinkList类指针即为指向单链表的头指针*/
typedef struct LNode
{   
    ElemType data;
    struct  LNode *next;

    
}LNode, *LinkList;

typedef LNode* It;

/*  c++表示法：
typedef struct LNode
{   
    ElemType data;
    LNode *next;
    
} *LinkList;

*/
It begin(LinkList L);
It end(LinkList L);
int find_val(LinkList L, ElemType e);
bool ListInsert_L(LinkList &L, int i, ElemType);
bool ListDelete_L(LinkList &L, int i, ElemType &e);
void CreateList_L_Reserved(LinkList &L, int n);
void CreateList_L_Sequential(LinkList &L, int n);
void ShowLinkList(const LinkList &l);
void MergList_L(LinkList &La,LinkList &Lb,LinkList &Lc);
void push_back(LinkList &L, ElemType e);
void push_front(LinkList &L, ElemType e);
void pop_back(LinkList &L, ElemType &e);
void pop_front(LinkList &L, ElemType &);
void insert_pos(LinkList &L, ElemType &, int pos);
void GetElem(LinkList &L, int i, ElemType &key);
int show_length(LinkList L);
bool delete_val(LinkList &L, ElemType &e, ElemType val);
void reverse(LinkList &L);
ElemType Input();
LinkList find(LinkList L, ElemType e);
void sort(LinkList &L);
void destroy(LinkList &L);
void clear(LinkList &L);
LinkList getNode(ElemType &e);
void insert(LinkList &L, It pos, ElemType &e);



//类似迭代器的东西，返回链表头节点和尾部节点的下一个节点（即NULL）
It begin(LinkList L){
    return L->next;
}

It end(LinkList L){
    LinkList p = L;
    while (p)   
        p = p->next; 
    return p;
}
LinkList getNode(ElemType &e){
    LinkList p = new LNode;
    p->data = e;
    p->next = NULL;
    return p;
}

void clear(LinkList &L){
    LinkList p = L->next;
    LinkList q;
    while (p)
    {   
      L->next = p->next;
      q = p;
      p = p->next;
      delete q;

    }
}



void destroy(LinkList &L){
    LinkList p = L;
    while (L)
    {   
        L = L->next;
        delete p;
        p = L;
        /* code */
    }
}


void sort(LinkList &L){                 //思路：将链表从第一个元素截断，分成两部分链表，分别拿第二个链表元素与第一个链表中的元素进行比较，按顺序插入第一个链表
    LinkList p = L->next->next, s;
    L->next->next = NULL;
    LinkList q = L;
    while (p)
    {
          while ((q->next)&&(p->data)>(q->next->data))
        {    
            q = q->next;
        }
        s = p;
        p = p->next;
        s->next = q->next;
        q->next = s;
        q = L;                  //注意将q置头节点，否则将插到第一个节点后面
    }  
}


void reverse(LinkList &L){
    LinkList s,p = L->next->next;
    L->next->next = NULL;
    while (p)
    {   
        s = p;
        p = p->next;
        s->next = L->next;
        L->next = s;
        /* code */
    }
}

LinkList find(LinkList L, ElemType e){
    LinkList p = L->next;
    while (p && p->data != e)   
        p = p->next;
    return p;
}
//按值查找返回元素指针





int find_val(LinkList L, ElemType e){
    LinkList p = L->next;
    int i = 1,flag = 0;
    while (p)
    {   
        if (p->data == e){
            flag = 1;
            break;
        }
        p = p->next;
        i++;
    }
    if (!flag)
    {   
        std::cout<<"No element found.\n";
        return 0;
    }
    
    return i;
}




bool delete_val(LinkList &L, ElemType &e, ElemType val){        //思路2：将当前节点的数据换为下一个节点的数据，然后删除下一个节点
    LinkList p = L,q;
    while (p)
    {   
        if (p->data == val)
            break;
        q = p;
        p = p->next;
        
    }
    if (!p)
    {   
        std::cout<<"Error, no value.\n";
        return false;
       
    }
    e = p->data;
    q->next = p->next;
    delete p;
    return true;
}


void GetElem(LinkList &L, int i, ElemType &key){
    LinkList p = L;
    int j = 0;
    while (p && j < i)
    {   
        p = p->next;
        j++;
        /* code */
    }
    if (!p && j<i)
    {   
        std::cout<<"Error,out of rang.\n";
        return ;
        /* code */
    }

    key = p->data;
    
    
}

int show_length(LinkList L){
    int len = 0;
    LinkList p = L;
    while (p->next)
    {   
        p = p->next;
        len++;
        /* code */
    }
    return len;
}


void insert_pos(LinkList &L, ElemType &e, int pos){
    LinkList p = L, q = L;
    LinkList s = new LNode;
    s->data = e;
    int i = 0;
    while (p && i < pos-1)
    {   
        p = p->next;
        i++;
       
    }
    if(!p && i < pos){
        std::cout<<"Error! Out of range.\n";
        return; 
    }
    s->next = p->next;
    p->next = s ;
    std::cout<<"Insert successful.\n";

}


//使用迭代器和getNode函数进行插入：
void insert(LinkList &L, It pos, ElemType &e){
    LinkList s = getNode(e);
    LinkList p = L;
    while (p->next != pos)
        p = p->next;
    s->next = p->next;
    p->next = s;
}

ElemType Input(){
    ElemType e;
    std::cout<<"Please enter element:";
    while (!(std::cin>>e))
    {      
        std::cin.clear();
        while (std::cin.get() != '\n')   
            continue;
        std::cout<<"Wrong Input, Please enter again:";
    }
    return e;
}


void pop_front(LinkList &L, ElemType &e ){
    LinkList p = L->next;
    e = p->data;
    L->next = p->next;
    delete p;
}

void pop_back(LinkList &L, ElemType &e){            //使用三个指针沿着链表往下顺，sq指向最后一个元素，使用p作为探针检查是否达到条件，q来储存前驱节点，来寻找倒数第二个元素
    LinkList p = L;
    /* while (p)
    {   
        q = p;
        p = p->next;
    }
    sq = q;
    e = sq->data;
    p = L;
   while (p != sq)
   {    
        q = p;
        p = p->next;
    
   }
    q->next = NULL;*/


    while (p->next->next)                   //方法2：不设探针，p->next指向下一个元素，下一个元素的next指针为空，则说明下一个元素是队尾元素。
        p = p->next;
    e = p->next->data;
    delete p->next;
    p->next = NULL;
}


void push_front(LinkList &L, ElemType e){
   /* LinkList p = new LNode;
    p->data = e;
    p->next = L->next;
    L->next = p;
    */
    //使用insert函数和迭代器进行头插
    insert(L,begin(L),e);
}



void push_back(LinkList &L, ElemType e){
   /* LinkList p = new LNode;
    p->data = e;
    LinkList q = L;
    while (q->next)             //没必要对q进行判定，对q的next指针进行判定即可。
        q = q->next;
    p->next = NULL;
    q->next = p;
    */
   //使用insert函数和迭代器进行尾插
   insert(L,end(L),e);

}


LinkList InitLinkList(){
    LNode* L = (LinkList)new LNode;        //对于结构体指针，在对其进行声明之后，会在栈中开辟空间用于存放指针本身，此时指针指向位置随机，成为悬浮指针。  
    if (L == NULL)                          //而对于结构体程序并未分配空间。这里就要使用new来为结构体分配空间，并令指针l指向开辟出来的地址
    {   
        exit(0);
        /* code */
    }
    L->data = 0;
    L->next = NULL;
    return L;
}

/*bool GetElem(LinkList L, int i, ElemType &e){               //寻找单链表中的第i个元素
    LinkList p = L->next;
    int j = 1;                  //初始化，此时p指向第一个节点，j为计数器，为指向第几个节点
    while (p&&j<i)              //这里注意，在链表中对值也好位置也好进行判定或者循环的时候，一定要把对于指针是否为空的判断放在前面，因为一旦放在后面，当指针走到链表尾，前面的对值判定由于表尾指针域为空无法得到值，就会导致崩溃。
    {   
        p = p->next;            //顺着指针往下查找，直到找到第i个节点或者遇到空指针（到达链表末尾）
        j++;
       
    }
    if (!p||j>i)
    return false;
    e = p->data;
    return true;
}
*/
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
    e = p->next->data;
    LinkList q = p->next;
    p->next = q->next;
    delete q;
    return true;
}



void CreateList_L_Reserved(LinkList &L, int n){       //时间复杂度：O(n)//头插，逆序创建  
    for (int i = n; i >0 ; --i)                         //对于函数参数来说，当函数要修改的是指向链表的指针时（这里创建列表涉及到更改头指针的值），要将Linklist类型按引用传递，即使它本身就是一个指针，这样才能对指针进行修改。
    {                                                   //而当函数要修改的是链表当中的内容或者对内容进行查看时，可以只传入LinkList指针，因为这并不涉及改变指针本身的值。
        LinkList p = (LinkList)new LNode;
        if (!p)
        {   
            exit(-1);
        }
               //创建新节点
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
    }
}

void CreateList_L_Sequential(LinkList &L, int n){               //尾插，顺序创建//时间复杂度：O(n)
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
        std::cout<<p->data<<"-->";
        p = p->next;            //不是线性表，往下遍历使用指针往下遍历，不能简单的将指针加一
        i++;
        /* code */
    }
    std::cout<<"NULL"<<std::endl;
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
    LinkList MyList;
    MyList = InitLinkList();
    ElemType elem, num;
    int select = -1;
    while (select)
    {   
        cout << "***************************************" << endl;
        cout << "*[1]push_back         [2]push_front   *" << endl;
        cout << "*[3]show_list         [4]pop_back     *" << endl;
        cout << "*[5]pop_front         [6]insert_pos   *" << endl;
        cout << "*[7]GetElem           [8]show_length  *" << endl;
        cout << "*[9]delete_val        [10]delete_pos  *" << endl;
        cout << "*[11]reverse          [12]sort        *" << endl;
        cout << "*[13]clear            [14]find        *" << endl;
        cout << "*[0]]quit                             *" << endl;
        cout << "***************************************" << endl;
        cout<<"Please enter your choice:";
        while (!(cin>>select))
        {   
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"Please enter a number:";
        }
        int pos;
        switch (select)
        {   
            case 0:
                cout<<"Bye!";
                break;
            case 1:
            cout<<"Please enter elements(q to quit):";
                while (cin>>elem)
                {
                    push_back(MyList, elem);\
                    /* code */
                }
                cin.clear();
                cin.get();
                break;
            case 2:
                cout<<"Please enter elements(q to quit):";
                while (cin>>elem)
                {   
                    push_front(MyList, elem);
                    /* code */
                }
                cin.clear();
                cin.get();
                break;
            case 3:
                ShowLinkList(MyList);
                break;
            case 4:
                pop_back(MyList, elem);
                cout<<elem<<" poped from the end of the list.\n";
                break;
            case 5:
                pop_front(MyList,elem);
                cout<<elem<<" poped from the front of the list.\n";
                break;
            case 6:
                cout<<"Enter position: ";
                cin>>pos;
                cin.get();
                elem = Input();
                insert_pos(MyList,elem,pos);
                break;
            case 7:
                cout<<"Please enter position: ";
                cin>>pos;
                cin.get();
                GetElem(MyList, pos, elem);
                cout<<"Element #"<<pos<<" is "<<elem<<endl;
                break;
            case 8:
                pos = show_length(MyList);
                cout<<"List length: "<<pos<<endl; 
                break;
            case 9:
                cout<<"Enter value: ";
                cin>>num;
                if(delete_val(MyList,elem,num))
                    cout<<elem<<" deleted from the list.\n";
                break;
            case 10:
                cout<<"Enter pos: ";
                cin>>pos;
                if(ListDelete_L(MyList,pos,elem))
                    cout<<elem<<" deleted from the list.\n";
                else
                    cout<<"Out of range.\n";
                break;
            case 11:
                reverse(MyList);
                break;
            case 12:
                sort(MyList);
                break;
            case 13:
                clear(MyList);
                break;
            case 14:
                elem = Input();
                pos = find_val(MyList,elem);
                if (pos)
                {
                    cout<<elem<<" is in the "<<pos<<" position.\n ";
                }
                break;
            default:
                cout<<"Wrong input, enter again.\n";
                break;       
        }
    }
    destroy(MyList);
    return 0;
}
