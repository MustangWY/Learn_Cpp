#include<iostream>
#include<string>
const int Arrsize = 20;
using namespace std;
int main (void){
    int i=0;
    string word;
    do
    {
        cout<<"Enter words (To stop enter the word done)";
        cin>>word;
        cin.get();
        i++;
        /* code */
    } while (word!="done");
    cout<<"you enter a totol of "<<i-1<<" words\n";
    return 0;
}