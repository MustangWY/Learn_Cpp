/**#include <string>
#include<iostream>
using namespace std;
int main (void) {
    string word;
    cout<<"Please enter a word: ";
    cin>>word;
    int i,j;
    for( i = 0, j = word.size()-1;i<j;i++,j--){
        char temp;
        temp=word[i];
        word[i]=word[j];
        word[j]=temp;
        
    }
    cout<<"the reversed word :"<<word;
    return 0;
}
**/
// forstr2.cpp -- reversing an array
#include <iostream>
#include <string>
#include <cstring>
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    char word[10];
    cin >> word;

    // physically modify string object
    char temp;
    int i, j;
    for (j = 0, i = strlen(word) - 1; j < i; --i, ++j)
    {                       // start block
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }                       // end block
    cout << word << "\nDone\n";
    // cin.get();
    // cin.get();
    return 0; 
}
