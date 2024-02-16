#include<iostream>
#include "stack.h"
#include<cctype>
int main(void){
    using namespace std;
    Stack st;
    char ch;
    Item po;
    cout<<"Please enter A to add a purchase order.\n"
        <<"P to process a PO, or Q to quit. \n";
    while (cin >> ch && toupper(ch) != 'Q') 
    {   
        while (cin.get() != '\n')
        {
            continue;
            /* code */
        }                   //一次只输入一个字母，把剩下的输入从输入流中删除
        if (!isalpha(ch))
        {   
            cout<<'\a';
            continue;
            /* code */
        }
        switch (ch)
        {
        case 'a':
        case 'A':
            cout<<"Enter customer name: ";
            cin.getline(po.fullname,35);
            cout<<"Emter customer payment: ";
            while (!(cin>>po.payment))
            {   
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout<<"Enter a number: ";
                
            }
            
            if (st.isfull())
            {   
                cout<<"Stack is full.\n";
                /* code */
            }else st.push(po);
            
            break;
        case 'P':
        case 'p':
            if (st.isempty())
            {
                cout<<"Stack is empty.\n";
                /* code */
            }
            else{
                st.pop(po);
                cout<<"customer "<<po.fullname<<" popped. \n";
            }
            break;
        
        
        }
        cout<<"Please enter A to add a purchase order.\n"
        <<"P to process a PO, or Q to quit. \n";
        /* code */
    }
    
    cout<<"Bye\n";

    return 0;
}