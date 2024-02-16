#include<iostream>
using namespace std;
const int ArSize = 10;
void strcount(const char* );
int main(void){
    char input[ArSize];
    char next;
    cout<<"Enter a line: "<<endl;
    cin.get(input,ArSize);
    while (cin)
    {   
        cin.get(next);
        while (next != '\n')
        {   
            cin.get(next);
            /* code */
        }
        strcount(input);
        cout<<"Entert next line (empty line to quit). \n";
        cin.get(input,ArSize);
        /* code */
    }
    
    cout<<"quitting...\n";
    return 0;
}

void strcount(const char* str){
    static int total  = 0; //无连接性的静态变量，在代码块中被定义，只在代码块被第一次调用时初始化，并且代码块不处于活动状态是仍然存在。
    int count = 0;
    cout<<"\""<<str<<"\"contains "; 
    while(*str++)
        count++;
    total+=count;
    cout<<count<<" characters ";
    cout<<total<<" total.\n";

}