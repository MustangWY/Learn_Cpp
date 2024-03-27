#include <iostream>
#include <new>
#include <cstdlib>
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10
#define OVERFLOW -1
typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
    /* data */
} Sqlist;

void MergeList_Sq(Sqlist L1, Sqlist L2, Sqlist &L3);
int LocateElem_Sq(Sqlist L, ElemType e, int (*compare)(ElemType, ElemType));
int InitList_SQ(Sqlist &L);
int ListInsert_Sq(Sqlist &l, int i, ElemType e);
int ListDelete_Sq(Sqlist &L, int i, ElemType &e);
int IsEqual(ElemType, ElemType);
void UnionList_Sq(Sqlist &La, Sqlist &Lb);
void ShowList(const Sqlist &L);
int push_back(Sqlist &, ElemType);
int push_front(Sqlist &l, ElemType e);
int pop_back(Sqlist &l, ElemType &e);
int pop_front(Sqlist &l, ElemType &e);
int find(Sqlist &l, ElemType e);
int Show_Length(Sqlist);
int deleteVal(Sqlist &l, ElemType);
void sort(Sqlist &l);
void reverse(Sqlist &L);
void clear(Sqlist &l);
void destroy(Sqlist &l);



void destroy(Sqlist &l)
{ // 清除表空间
    delete[] l.elem;
    l.elem = NULL;
    l.listsize = 0;
    l.length = 0;
}

void clear(Sqlist &l)
{ // 清除表中的元素
    l.length = 0;
    std::cout << "List cleared.\n";
}

void reverse(Sqlist &L)
{
    if (L.length == 0 || L.length == 1)
    {
        return;
        /* code */
    }

    ElemType *p = L.elem;
    for (int i = 0; i < L.length / 2; i++) // 不管是奇数还是偶数交换次数都等于长度除以二
    {
        ElemType temp = *(p + i);
        *(p + i) = *(p + L.length - 1 - i); //(p+i)相当于低位指针，（p+length-1-i)相当于高位指针
        *(p + L.length - 1 - i) = temp;     // 边界条件可以简化为while(low<high)即可。。。。。
    }
}

void sort(Sqlist &l)
{ // 冒泡排序
    ElemType *p = l.elem;
    if (l.length == 0)
    {
        std::cout << "Empty list.\n";
        return;
        /* code */
    }
    bool flag = false;
    for (int i = 0; i < l.length - 1; i++)
    {
        for (int j = 0; j < l.length - 1 - i; j++)
        {
            if (*p > *(p + 1))
            {
                flag = true;
                ElemType temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
            p++;
        }
        if (!flag)
            break; // 进行完一轮排序之后，判断本轮排序是否有元素交换。如果没有则列表已经有序，终止循环
        else
            flag = false;
        p = l.elem; // 注意进行完一轮排序以后，将指针重新指向列表头
    }
}

int Show_Length(Sqlist l)
{
    return l.length;
}

int find(Sqlist &l, ElemType e)
{
    for (int i = 0; i < l.length; i++)
    {
        if (l.elem[i] == e)
        {
            return ++i;
            /* code */
        }

        /* code */
    }
    return -1;
}

int pop_back(Sqlist &l, ElemType &e)
{ // 尾部删除
    if (l.length == 0)
    {
        return 0;
    }
    e = *(l.elem + l.length - 1);
    l.length--;
    return 1;
}
int pop_front(Sqlist &l, ElemType &e)
{ // 头部删除
    if (l.length == 0)
    {
        return 0;
    }
    e = *l.elem;
    ElemType *p = l.elem + 1;
    while (p <= l.elem + l.length)
    {
        *(p - 1) = *p; // p指向第二个元素，将其向前移动一位，然后将p向后指
        p++;
    }
    l.length--;
    return 1;
}

int push_back(Sqlist &l, ElemType e)
{ // 尾插
    int flag = 0;
    // 可以单写一个分配函数
    if (l.length >= l.listsize)
    {
        ElemType *newbase = new (l.elem) ElemType[LISTINCREMENT + l.listsize];
        if (!newbase)
        {
            std::cout << "List full, unable to allocate new memory.\n";
            return 0;
        }
        l.elem = newbase;
        l.listsize += LISTINCREMENT;
        std::cout << "List full, allocate new memory.\n ";
    }
    *(l.elem + l.length) = e; // 尾插，表首指针往后偏移表长个单位即为表尾元素
    l.length++;
    flag = 1;
    return flag;
}

int push_front(Sqlist &l, ElemType e)
{ // 头插
    int flag = 0;
    if (l.length >= l.listsize)
    {
        ElemType *newbase = new (l.elem) ElemType[LISTINCREMENT + l.listsize];
        if (!newbase)
        {
            std::cout << "List full, unable to allocate new memory.\n";
            return flag;
        }
        l.elem = newbase;
        l.listsize += LISTINCREMENT;
        std::cout << "List full, new memory allocated.\n ";
    }

    ElemType *p = l.elem + l.length - 1;

    while (l.elem <= p) // p指向表尾，将p指向的元素移动到其后面的位置。然后将p往前指
    {
        *(p + 1) = *p;
        p--;
        /* code */
    }
    *l.elem = e;
    l.length++;
    flag = 1;
    return flag;
}

int InitList_SQ(Sqlist &L)
{ // 定义顺序表后表成员均为不确定值，并且没有表空间。
  // 为顺序表基本空间进行开辟，并且初始化表长和容量
    L.elem = new ElemType[LIST_INIT_SIZE];
    if (!L.elem)
    {
        exit(OVERFLOW);
        /* code */
    }

    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;
}

int ListInsert_Sq(Sqlist &l, int i, ElemType e)
{                                      // 时间复杂度n/2
    if ((i < 1) || (i > l.length + 1)) // 这里i指的是元素个数，从1开始算起
    {
        return 0;
    }
    if (l.length >= l.listsize)
    {
        ElemType *newbase = new (l.elem) ElemType[LISTINCREMENT + l.listsize];
        if (!newbase)
        {
            exit(OVERFLOW);
        }
        l.elem = newbase;
        l.listsize += LISTINCREMENT;
    }
    ElemType *q = &l.elem[i - 1];
    ElemType *p = &l.elem[l.length - 1];
    while (q <= p)
    {
        *(p + 1) = *p;
        p--;
    } // 指针p指向线性表末尾，指针q指向插入位置，只要指针p不等于指针q，那么p指向的后一个元素等于p指向的元素，全部元素向后挪，将p--得到下一个。

    *q = e;
    l.length++;
    return 1;
}

int ListDelete_Sq(Sqlist &L, int i, ElemType &e)
{ // 时间复杂度：(n-1)/2
    if ((i < 1) || (i > L.length))
    {
        return 0;
        /* code */
    }
    ElemType *q = &L.elem[i - 1];
    ElemType *p = &L.elem[L.length - 1];
    e = L.elem[i - 1];
    while (q <= p)
    {
        *q = *(q + 1);
        q++; // 指针p指向线性表末尾，指针q指向删除位置，只要指针q不等于指针p，指针q指向的值就等于指针q指向的下一个位置的值
        /* code */
    }
    L.length--;
    return 1;
}

int IsEqual(ElemType e1, ElemType e2)
{
    return (e1 == e2);
}

int LocateElem_Sq(Sqlist L, ElemType e, int (*compare)(ElemType, ElemType))
{
    int i = 0;
    for (i; i < L.length; i++)
    {
        if (compare(L.elem[i], e)) // 函数名相当于函数指针，可以直接拿来用，如果线性表中的元素满足与元素e的compare关系，则停止循环，并且返回线性表中第一个满足的元素位置
            break;
        /* code */
    }
    if (i < L.length)
    {
        return i + 1;
        /* code */
    }
    else
        return 0;
}

void MergeList_Sq(Sqlist L1, Sqlist L2, Sqlist &L3)
{
    InitList_SQ(L3);
    int i = 1, j = 1;
    int k = 0;
    while ((i <= L1.length) && (j <= L2.length))
    {
        if (L1.elem[i - 1] > L2.elem[j - 1])
        {
            ListInsert_Sq(L3, ++k, L2.elem[j - 1]); // 可以直接使用下标进行赋值
            j++;
            /* code */
        }
        else
        {
            ListInsert_Sq(L3, ++k, L1.elem[i - 1]);
            i++;
        }

        /* code */
    }
    while (i <= L1.length)
    {
        ListInsert_Sq(L3, ++k, L1.elem[i - 1]);
        i++;
        /* code */
    }
    while (j <= L2.length)
    {
        ListInsert_Sq(L3, ++k, L2.elem[j - 1]);
        j++;
        /* code */
    }
}

void UnionList_Sq(Sqlist &La, Sqlist &Lb)
{
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;
    int i = 0, j = 0;
    for (i; i < La.length; i++)
    {
        for (j; j < Lb.length; j++)
        {
            if (!(*(pa + i) == *(pb + j))) // 将b表插入到a表后面，分别取出b表元素，与a表元素相比较，不同就将b表元素插入a表后面，相同不做操作。
                                           // 这里注意i和j的作用域
            {
                ListInsert_Sq(La, La.length + 1, *(pb + j));
            }
        }
    }
}
void ShowList(const Sqlist &L)
{
    for (int i = 0; i < L.length; i++)
    {
        std::cout << L.elem[i] << ' ';
        /* code */
    }
    std::cout << std::endl;
}

int deleteVal(Sqlist &l, ElemType e)
{
    ElemType *p = l.elem;
    ElemType a;
    int i = 0;
    // 可以使用find函数进行寻找
    for (i; i < l.length; i++)
    {
        if (l.elem[i] == e)
        {
            break;
            /* code */
        }

        /* code */
    }
    if (i >= l.length)
    {
        std::cout << "Value not exist.\n";
        return 0;
    }
    else
    {
        ListDelete_Sq(l, i + 1, a);
        return 1;
    }
}

int main(void)
{
    using namespace std;
    int select = 1;
    Sqlist MyList;
    InitList_SQ(MyList);
    while (select)
    {
        cout << "***************************************" << endl;
        cout << "*[1]push_back         [2]push_front   *" << endl;
        cout << "*[3]show_list         [4]pop_back     *" << endl;
        cout << "*[5]pop_front         [6]insert pos   *" << endl;
        cout << "*[7]find              [8]show_length  *" << endl;
        cout << "*[9]delete_pos        [10]delete_val  *" << endl;
        cout << "*[11]sort             [12]reverse     *" << endl;
        cout << "*[13]clear            [0]quit         *" << endl;
        cout << "***************************************" << endl;
        /* code */
        cout << "Please select:";
        while (!(cin >> select))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please enter a number:";

            /* code */
        }
        ElemType num;
        int flag;
        int pos; // switch内的变量初始化最好放在switch外面，否则当switch语句跳转到不包含初始化的情况时会引用空对象
        switch (select)
        {
        case 0:
            break;
        case 1:

            cout << "Please enter a number(q to stop): ";
            while (cin >> num) // 逗号表达式，看逗号之后的表达式之后的真假
            {
                push_back(MyList, num);
                /* code */
            }
            cin.clear();                    //cin在接收到不相容的数据类型时，cin对象中的一个错误标记被设置，对cin方法的调用将返回false
            cin.get();
            
            break;
        case 2:
            cout << "Please enter a number(q to stop): ";
            while (cin >> num) // 逗号表达式，看逗号之后的表达式之后的真假
            {
                push_front(MyList, num);
                /* code */
            }
            cin.clear();
            cin.get();
            break;
        case 3:
            ShowList(MyList);
            break;
        case 4:
            flag = pop_back(MyList, num);
            if (!flag)
            {
                cout << "Error, empty list.\n";
                break;
                /* code */
            }
            cout << num << " Poped from the end\n";
            break;
        case 5:
            flag = pop_front(MyList, num);
            if (!flag)
            {
                cout << "Error, empty list.\n";
                break;
                /* code */
            }
            cout << num << " Poped from the front\n";
            break;
            break;
        case 6:
            cout << "Please enter the number: ";
            (cin >> num).get();
            cout << "Please enter position ";
            (cin >> pos).get();
            flag = ListInsert_Sq(MyList, pos, num);
            if (!flag)
            {
                cout << "Wrong position.\n";
                break;
                /* code */
            }
            break;
        case 7:
            int pos;
            cout << "Enter the number you want to find:";
            (cin >> num).get();
            pos = find(MyList, num);
            if (pos == -1)
            {
                cout << "Not exist\n";
                break;
                /* code */
            }
            else
            {
                cout << num << " is the " << pos << " number.\n";
                break;
            }

        case 8:
            cout << "the length of the list is: " << Show_Length(MyList) << endl;
            break;
        case 9:
            cout << "Enter position: ";
            cin >> pos;
            flag = ListDelete_Sq(MyList, pos, num);
            if (!flag)
            {
                cout << "Out of range.\n";
                /* code */
            }
            else
                cout << "Delete successful\n";
            break;
        case 10:
            cout << "Enter value: ";
            cin >> num;
            cin.get();
            deleteVal(MyList, num);
        case 11:
            sort(MyList);
            break;
        case 12:
            reverse(MyList);
            break;
        case 13:
            clear(MyList);
            break;
        // case 14:
        //  destroy(MyList);
        // break;
        default:
            cout << "Wrong input, enter again:\n";
            break;
        }
    }
    destroy(MyList);
    return 0;
}