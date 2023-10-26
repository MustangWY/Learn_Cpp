#include<iostream>
using namespace std;
int main(void){
    char ch;
    cout<<"Please enter one of the following choices: "<<endl;
    cout<<"c) carnivore \t"<<"p) pianist"<<endl;
    cout<<"t) tree \t"<<"g) game "<<endl;
    int test = 1;
    while (test)
    {
        cin>>ch;
       switch (ch)
    {
        case 'c':cout<<"carnivore";
            test=0;
            break;//switch语句中的break标签用于终止switch操作，不向下进行判定。若不带break语句switch跳到特定行后，将会继续向下执行语句。
        case 'p':cout<<"pianist";
            test=0;
            break;
        case 't':cout<<"A maple is a tree.";
            test=0;
            break;
        case 'g':cout<<"Currently I'm playing Call of Duty MW2.";
            test=0;
            break;
        default:cout<<"Please enter a c, p, t or g: ";
            break;
    }
  
    }
    return 0;
}