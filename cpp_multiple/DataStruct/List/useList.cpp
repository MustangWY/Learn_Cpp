#include"list.h"
#include<iostream>

int main(void){
    using namespace std;
    Sqlist MyList;
    int select = 1;
    while (select)
    {   
        cout<<"***************************************"<<endl;
        cout<<"*[1]push_back         [2]push_front   *"<<endl;
        cout<<"*[3]show_list         [4]pop_back     *"<<endl;
        cout<<"*[5]pop_front         [6]insert pos   *"<<endl;
        cout<<"*[7]find              [8]show_length  *"<<endl;
        cout<<"*[9]delete_pos        [10]delete_val  *"<<endl;
        cout<<"*[11]sort             [12]reverse     *"<<endl;
        cout<<"*[13]clear            [14]destroy     *"<<endl;
        cout<<"*[0]quit                              *"<<endl;
        cout<<"***************************************"<<endl;
        /* code */
        cout<<"Please select:";
        while (!(cin>>select))
        {   
            cin.clear();
            while (cin.get()!='\n')
                continue;
            cout<<"Please enter a number:";
            
            /* code */
        }
        ElemType num;
        int flag;     
        int pos;              //switch内的变量初始化最好放在switch外面，否则当switch语句跳转到不包含初始化的情况时会引用空对象                    
        switch (select)
        {
        case 0:
            break;
        case 1:
            
            cout<<"Please enter a number(-1 to stop): ";
            while (cin>>num,num != -1 ) //逗号表达式，看逗号之后的表达式之后的真假
            {   
                MyList.push_back(num);
                cin.get();
                /* code */
            }  
            break;
        case 2:
            cout<<"Please enter a number(-1 to stop): ";
            while (cin>>num,num != -1 ) //逗号表达式，看逗号之后的表达式之后的真假
            {   
                MyList.pop_front(num);
                cin.get();
                /* code */
            }  
            break;
        case 3:
            MyList.ShowList();
            break;
        case 4:
            flag = MyList.pop_back(num);
            if (!flag)
            {   
                cout<<"Error, empty list.\n";
                break;
                /* code */
            }
            cout<<num<<" Poped from the end\n";
            break;
        case 5:
            flag = MyList.pop_front(num);
            if (!flag)
            {   
                cout<<"Error, empty list.\n";
                break;
                /* code */
            }
            cout<<num<<" Poped from the front\n";
            break;
            break;
        case 6:
            cout<<"Please enter the number: ";
            (cin>>num).get();
            cout<<"Please enter position ";
            (cin>>pos).get();
            flag = MyList.ListInsert_Sq(pos,num);
            if (!flag)
            {   
                cout<<"Wrong position.\n";
                break;
                /* code */
            }
            break;
        case 7:
            int pos; 
            cout<<"Enter the number you want to find:";
            (cin>>num).get();
            pos = MyList.find(num);
            if (pos == -1)
            {   
                cout<<"Not exist\n";
                break;
                /* code */
            }else {
                cout<<num<<" is the "<<pos<<" number.\n";
                break;
            }
            
            
        case 8:
            cout<<"the length of the list is: "<<MyList.Show_Length()<<endl;
            break;
        case 9:
            cout<<"Enter position: ";
            cin>>pos;
            flag = MyList.ListDelete_Sq(pos,num);
            if (!flag)
            {   
                cout<<"Out of range.\n";
                /* code */
            }else 
                cout<<"Delete successful\n";
            break;
        case 10:
            cout<<"Enter value: ";
            cin>>num;
            cin.get();
            MyList.deleteVal(num);
        case 11:
            MyList.sort();
            break;
        case 12:
            MyList.reverse();
            break;
        case 13:
            MyList.clear();
            
        default:
            cout<<"Wrong input, enter again:\n";
            break;
        }
        
        
    }
    return 0;

}