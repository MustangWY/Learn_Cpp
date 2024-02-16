#include<iostream>
using namespace std;
void other();
void another();
int x = 10;
int y;

int main(void){

    cout<<x<<endl;
    {
        int x = 4;
        cout<<x<<endl;
        cout<<y<<endl;
    }
    other();
    another();
}

void other(){

    int y = 1;
    cout<<"Other: "<<x<<", "<<y<<endl;
}

