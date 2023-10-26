#include <iostream>
using namespace std;
void n_chars(char,int);
int main(void){

    int times;
    char ch;
    cout<<"enter a character: ";
    cin>>ch;
    while (ch!='q')
    {
        cout<<"Enter an intiger: ";
        cin>>times;
        n_chars(ch,times);
        cout<<"Enter another intiger or enter q to quit.";
        cin>>ch;
    }

    return 0;
}
void n_chars(char c,int n){
        while (n-->0)
        {
            cout<<c;
        }
        
    }