#include<iostream>
using namespace std;
int main (void) {
    char ch;
    cout<<"Please enter text, end with a #:\n";
    //cin>>ch;
    cin.get(ch);
    int count = 0;
    //while (ch!='#')
    while(cin.fail() == false)//eof检测，ctrl+z视为eof，fail函数为真，否则fail（）函数为假
    {
        cout<<ch;
        count++;
        cin.get(ch);//cin.get读取输入中得下一个字符包括空格
        //cin>>ch;//cin会跨过空格和空白字符和换行字符
        /* code */
    }
    cout<<endl<<count<<" characters read ";
    
    return 0;
}