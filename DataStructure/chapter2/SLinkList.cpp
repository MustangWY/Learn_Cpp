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
void push_front(SLinkList &space, ElemType e);
void ShowSlist(const SLinkList &space);
void Free_SL(SLinkList &space, int k);
bool DeleteList_SL(SLinkList &space, int k);
void push_back(SLinkList &space, ElemType e);



void push_back(SLinkList &space, ElemType e){
    int i = Malloc_SL(space);
    int j = space[0].cur;
    if (!i)
    {   
        std::cout<<"Cannot allocate space.\n";
        return;
        /* code */
    }
    while (space[j].cur != -1)
    {   
        j = space[j].cur;
        /* code */
    }
    space[i].data = e;
    space[i].cur = -1;
    space[j].cur = i;
    
    
}



void initSpace_SL(SLinkList &space){
    
    for (int i = 1; i < MAXSIZE-1; i++)//初始化space，将space里第二个元素以后每一个元素的cur指定为下一个元素的位置，space[0].cur为头指针，-1表示空指针
                                        //这里将space[0]作为数据链表的头指针，space[1]作为备用链表的头指针，并且数据链表以-1表示表尾
    {   
        space[i].cur = i+1;
        /* code */
    }
    space[MAXSIZE-1].cur = 0;
    space[0].cur = -1;
}

int Malloc_SL(SLinkList &space){
    int i = space[1].cur;                   //获取空间池中头节点的游标，即表示空间池中下一个可用节点的位置
    if (space[1].cur)
    {   
        space[1].cur = space[i].cur;            //将空间池中的头节点的游标指向刚才提出来的节点的下一个节点，即第i个节点的下一个节点
        /* code */
    }else return 0;

    return i;
    

}

void ShowSlist(const SLinkList &space){
    int i = space[0].cur;
    while (i!=-1)
    {   
        std::cout<<space[i].data<<"-->";;
        
        i = space[i].cur;
        /* code */
    }
    std::cout<<"NULL\n";
    
}
void push_front(SLinkList &space, ElemType e){
    int i =Malloc_SL(space);
    if (!i)
    {   
        std::cout<<"Allocation failed.\n";
        return;
        /* code */
    }
    space[i].data = e;
    space[i].cur = space[0].cur;        //头插
    space[0].cur = i;
    
}

void Free_SL(SLinkList &space, int k){          //注意这里是释放空间而不是删除空间，只需将要释放的元素下标传入，将其插入备用池中即可
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
    using namespace std;
    SLinkList sp;
    ElemType elem;
    initSpace_SL(sp);
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
        cout << "*[13]clear          [14]find        *" << endl;
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
        switch (select){
            case 0:
                cout<<"Bye!\n";
                break;
            case 1:
                cout<<"Pleae enter elements(q to quit): ";
                while (cin>>elem)
                {   
                    push_front(sp,elem);
                }
                cin.clear();
                cin.get();
                break;
            case 2 :
                cout<<"Pleae enter elements(q to quit): ";
                while (cin>>elem)
                {   
                    
                    push_back(sp,elem);
                }
                cin.clear();
                cin.get();
                break;
            case 3: 
                ShowSlist(sp);
                break;
            default:
                cout<<"Wrong input.\n";
                break;
        



        }
    
}
    return 0;
}