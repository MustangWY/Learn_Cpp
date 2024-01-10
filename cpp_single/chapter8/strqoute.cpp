#include<string>
#include <iostream>
using namespace std;

string version1(const string &s1,const string &s2);
const string& version2(string &s1,const string &s2);
const string & version3(string &s1,const string &s2);
int main(void){
    string input;
    string result;
    string copy;
    
    cout<<"Enter a string: ";
    getline(cin,input);
    copy = input;
    cout<<"You entered: "<<input<<endl;
    result = version1(input,"***");
    cout<<"Your string enhanced: "<<result<<endl;
    cout << "Original string: " << input << endl;
    cout << "******************************" << endl;

    result = version2(input,"###");
    cout<<"Your string enhanced: "<<result<<endl;
    cout << "Original string: " << input << endl;
    cout << "******************************" << endl;//s1 changed

   result = version3(copy,"@@@");
    cout<<"Your string enhanced: "<<result<<endl;
    cout << "Original string: " << copy << endl;
    cout << "******************************" << endl;//s1 changed

    return 0;
 }

string version1(const string &s1,const string &s2){
    string temp;
    temp = s2+s1+s2;
    return temp;
}
const string& version2(string &s1,const string &s2){
    s1 = s2 + s1 + s2;
    return s1;
}
const string & version3(string &s1,const string &s2){
    string temp;
    temp = s2 + s1 + s2;
    return temp; //reference to local variable 'temp' returned

}