#include <iostream>
#define MAXSIZE 10   
//#define ElemType int
/*
*   这里可以将结构中的cur当成指针去思考，
*   插入弹出等操作可以直接套用链表操作，只不过将链表中的指针替换为cur就好。
*/
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
void push_back(SLinkList &space, ElemType e);
void pop_back( SLinkList &space, ElemType &e);
void pop_front( SLinkList &space, ElemType &e);
void insert_pos(SLinkList &space, ElemType e, int pos);
void GetElem(SLinkList &space, ElemType &e, int pos);
int show_length(SLinkList const &space);
void delete_val(SLinkList &space, ElemType e);
void delete_pos(SLinkList &space, ElemType &e,int pos);
void sort(SLinkList &space);
void reverse(SLinkList &space);
void clear(SLinkList &space);
int find_val(SLinkList space, ElemType e);



int find_val(SLinkList space, ElemType e){
    int plist = space[0].cur;
    int pos = 1;
    while (space[plist].cur != -1 && space[plist].data != e)
    {   
        plist = space[plist].cur;
        pos++;
        /* code */
    }
    if (space[plist].cur == -1 && space[plist].data != e )
    {   
        std::cout<<"No element.\n";
        return 0;
        /* code */
    }
    return pos;
    




}

void clear(SLinkList &space){
    int plist = space[0].cur;
    int temp = 0;
    space[0].cur = -1;
    while (plist != -1)
    {   
        temp = plist;
        plist = space[plist].cur;   //要先将指针往下移再释放空间！！！！！！！！！！！同时要使用一个temp放置当前节点位置，不然就删下一个节点了！！！！！！！！！！！！
        Free_SL(space, temp);
        /* code */
    }
}



void sort(SLinkList &space){            //注意第二个循环判断条件，如果直接判断游标是否等于-1则最后list1一定等于-1，会造成出界
                                        //同样单链表中检查的也是也是q->next，否则会有segmentation fault、

    int list1 = 0;
    int list2 = space[space[0].cur].cur;
    space[space[0].cur].cur = -1;
    int temp;
    while (list2 != -1)
    {   
        while (space[list1].cur != -1 && space[list2].data>space[space[list1].cur].data)
        {
            list1 = space[list1].cur;
            /* code */
        }
        int temp = list2;
        list2 = space[list2].cur;
        space[temp].cur = space[list1].cur;
        space[list1].cur = temp;
        list1 = 0;
        
        /* code */
        
    }
    

}



void reverse(SLinkList &space){
    int list1 = 0;
    int list2 = space[space[0].cur].cur;
    space[space[list1].cur].cur = -1;
    int temp = 0;
    while (list2 != -1) 
    {   
        temp = list2;
        list2 = space[list2].cur;
        space[temp].cur = space[list1].cur;
        space[list1].cur = temp;

    }
    
}


void delete_pos(SLinkList &space, ElemType &e,int pos){
    int i = 0;
    int j = 0,count = 0;
    while(space[i].cur != -1 && count < pos){
        j = i;
        i = space[i].cur;
        count++;
    }
    if(space[i].cur == -1 && count < pos){
        std::cout << "Out of range.\n";
        return;
    }
    e =space[i].data;
    space[j].cur = space[i].cur;
    Free_SL(space, i);

}



void delete_val(SLinkList &space, ElemType e){
    int i = space[0].cur;
    int j = 0;                  //i作为探针指向要删除的元素，j作为前驱指向前一个元素
    while (space[i].cur != -1 && space[i].data != e)
    {   
        j = i;
        i = space[i].cur;
        /* code */
    }
    if (space[i].cur == -1 && space[i].data != e)
    {   
        std::cout<<"No value.\n";
        return;
        /* code */
    }
    space[j].cur = space[i].cur;
    Free_SL(space,i);

}



int show_length(SLinkList const &space){
    int i = space[0].cur;
    int length = 0;
    while (i != -1)
    {   
        i = space[i].cur;
        length++;
        /* code */
    }
    return length;
}



void GetElem(SLinkList &space, ElemType &e, int pos){
    int i = 0, count = 0;
    while (space[i].cur != -1 && count < pos)
    {   
        i = space[i].cur;
        count++;
    }
    if (space[i].cur == -1 && count < pos)
    {   
        std::cout<<"Out of range.\n";
        return ;
    }
    e = space[i].data;
    std::cout<<"Element #"<<pos<<" is "<<e<<std::endl;
}



void insert_pos(SLinkList &space, ElemType e, int pos){
    int i = 0, count = 0;
    int j = Malloc_SL(space);
    if (!j)
    {   
        std::cout<<"Allocate failed.\n";
        return;
        /* code */
    }
    
    while (space[i].cur != -1 && count<pos-1)
    {   
        i = space[i].cur;
        count++;
        /* code */
    }
    if (space[i].cur == -1 && count < pos)
    {   
        std::cout<<"Out of range.\n";
        return;
        /* code */
    }
    
    space[j].data = e;
    space[j].cur = space[i].cur;
    space[i].cur = j;
    

}

void pop_front( SLinkList &space, ElemType &e){
    if (space[0].cur == -1)
    {   
        std::cout<<"No element\n";
        return;
        /* code */
    }
    int i = space[0].cur;
    e = space[i].data;
    space[0].cur = space[i].cur;
    Free_SL(space, i);
}

void pop_back( SLinkList &space, ElemType &e){
    int i = space[0].cur;
    if (i == -1)
    {
        std::cout<<"No elemet.\n";
        return;
    }
    
    while (space[space[i].cur].cur != -1)
    {   

        i = space[i].cur;
        /* code */
    }
    e = space[space[i].cur].data;
    Free_SL(space, space[i].cur);
    space[i].cur = -1;
}


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




int main(void){
    using namespace std;
    SLinkList sp;
    ElemType elem;
    int pos;
    initSpace_SL(sp);
    int length = 0;
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
        switch (select){
            case 0:
                cout<<"Bye!\n";
                break;
            case 1:
                cout<<"Pleae enter elements(q to quit): ";
                while (cin>>elem)
                {   
                    push_back(sp,elem);
                }
                cin.clear();
                cin.get();
                break;
            case 2 :
                cout<<"Pleae enter elements(q to quit): ";
                while (cin>>elem)
                {   
                    
                    push_front(sp,elem);
                }
                cin.clear();
                cin.get();
                break;
            case 3: 
                ShowSlist(sp);
                break;
            case 4:
                pop_back(sp,elem);
                cout<<elem<<" Poped from the end of the list.\n";
                break;
            case 5:
                pop_front(sp,elem);
                cout<<elem<<" Pop from the front of the list.\n";
                break;
            case 6:
                cout<<"Enter position: ";
                cin>>pos;
                cout<<"Enter element: ";
                cin>>elem;
                insert_pos(sp, elem, pos);
                break;
            case 7:
                cout<<"Enter position: ";
                cin>>pos;
                GetElem(sp, elem, pos);
                
                break;
            case 8:
                cout<<"the list is "<<show_length(sp)<<" elements long.\n";
            break;
            case 9:
                cout<<"Enter the value: ";
                cin>>elem;
                delete_val(sp,elem);
                cout<<elem<<" deleted from the list.\n";
            break;
            case 10:
                cout<<"Enter the position: ";
                cin>>pos;
                delete_pos(sp,elem,pos);
                cout<<elem<<" deleted from the list.\n";
            break;
            case 11:
                reverse(sp);
                break;
            case 12:
                sort(sp);
                break;
            case 13:
            clear(sp);
                break;
            case 14:
            cout<<"Enter element:";
            cin>>elem;
            pos = find_val(sp,elem);
            if (pos)
            {   
                cout<<"element "<<elem<< "is in the "<< pos <<" position.\n";
            }
            break;
            default:
                cout<<"Wrong input.\n";
                break;
        



        }
    
}
    return 0;
}