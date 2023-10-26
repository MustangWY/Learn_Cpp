#include<iostream>
#include<cctype>
using namespace std;
int main(void){
    char ch;
    cout<<"Enter anything, enter @ to exit"<<endl;
    cin.get(ch);

    while ((ch!='@'))
    {
        if (isalpha(ch))
        {
           cout<<"Your input: "<<ch<<endl;
            if (isupper(ch))
                ch=tolower(ch);
            else 
                ch=toupper(ch);
        cout<<"After transformation: "<<ch<<endl;
        cin.get(ch); 
        /* code */
        } else
        {
            cin.get(ch);
            continue;
        }
        
    }
    
   
    
    return 0;
}