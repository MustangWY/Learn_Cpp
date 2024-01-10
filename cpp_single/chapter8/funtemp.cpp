#include<iostream>
using namespace std;
template <typename T>
void swap1 (T &a, T &b);
int main(void){
    
    int i = 10;
    int j = 20;
    cout<<"i,j = "<<i<<','<<j<<endl;
    swap1(i,j);
    cout<<"After swap, i,j = "<<i<<','<<j<<endl;
     
    cout<<"i,j = "<<i<<','<<j<<endl;
    double x = 22.0;
    double y = 11.1;
    cout<<"x,y = "<<x<<','<<j<<endl;
    swap1(x,y);
    cout<<"After swap, i,j = "<<i<<','<<j<<endl;
    return 0;
}
template <typename T>
void swap1 (T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;

}