#include<iostream>
using namespace std;
void showmenu();
void report();
void comfort();
int main (void){
    showmenu();
    int choice;
    cin>>choice;
    while (choice != 5){
        switch (choice)
        {
        case 1: cout<<"WARNING!\n";
            break;
        case 2: report();
            break;
        case 3: cout<<"The boss was in all day.\n";
            break;
        case 4:comfort();
            break;
        default:cout<<"That was not a choice.\n";
            break;
        }
        showmenu();
        cin>>choice;
    }
}
void showmenu(){
    cout<<"Please enter 1,2,3,4 or 5\n"
            "1)alarm          2)report\n"
            "3)alibi          4)comfort\n"
            "5)quit\n";
}
void report(){
    cout<<"Its been an excellent week for business.\n"
    "Sales are up 120%. Expenses are down 35%.\n";
}
void comfort(){
    cout<<"Your employees think you are the finest CEO.\n";
}