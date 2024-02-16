#include<iostream>
using namespace std;
void oil(int x);
int main(void){
    int texas = 31;
    int year = 2011;
    cout<<"Int main(), texas = "<<texas<<' ';
    cout<<"int main(),texas address = "<<&texas<<endl;
    cout<<"Int main(), year = "<<year<<' ';
    cout<<"int main(),year address = "<<&year<<endl;
    oil(texas);
    cout<<"Int main(), year = "<<year<<' ';
    cout<<"int main(),year address = "<<&year<<endl;
    return 0;
}

void oil(int x){
    int texas = 5;


    cout<<"tne oil texas: "<<texas<<' ';
    cout<<"the oil texas address: "<<&texas<<endl;
    cout<<"tne oil x: "<<x<<' ';
    cout<<"the oil x address: "<<&x<<endl;
    {
        int texas = 113;
        cout<<"in block texas: "<<texas<<' ';
        cout<<"in block texas address: "<<&texas<<endl;
         cout<<"in block x: "<<x<<' ';
        cout<<"in block x address: "<<&x<<endl;
    }
    cout<<"tne post-block texas: "<<texas<<' ';
    cout<<"the post-block texas address: "<<&texas<<endl;
}