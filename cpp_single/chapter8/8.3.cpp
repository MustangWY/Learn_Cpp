#include<iostream>
#include<string> 
#include<cctype>
using namespace std;
void transform(string &str);
int main(void){
    string str;
    cout<<"Enter a string (q to quit): ";
    
    while (getline(cin,str))
    {   
        if (str[0] == 'q'&&str[1] == '\0')
        {
            cout<<"bye"<<endl;
            break;
        }
        transform(str);
        cout<<str<<endl;
        cout<<"Enter a string (q to quit): ";
        /* code */
    }
    
    return 0;
}
void transform(string &str){
    int i = 0;
    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
}
