#include<iostream>
#include<cstring>
const int Arrsize = 20;
using namespace std;
int main (void){
    int i=0;
    char word[Arrsize];
    do
    {
        cout<<"Enter words (To stop enter the word done)";
        cin>>word;
        i++;
        /* code */
    } while (strcmp(word,"done"));
    cout<<"you enter a totol of "<<i-1<<" words\n";
    return 0;
}