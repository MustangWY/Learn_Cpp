#include<iostream>
using namespace std;
const int limit = 8;
template <typename T>
void swap1 (T &a, T &b);
void show(int arr[], int n);
template <typename T>
void swap1 (T a[], T b[], int n);
int main(void){
    
    int i = 10;
    int j = 20;
    cout<<"i,j = "<<i<<','<<j<<endl;
    swap1(i,j);
    cout<<"After swap, i,j = "<<i<<','<<j<<endl;
     
    cout<<"i,j = "<<i<<','<<j<<endl;
    double x = 22.0;
    double y = 11.1;
    cout<<"x,y = "<<x<<','<<y<<endl;
    swap1(x,y);
    cout<<"After swap, i,j = "<<x<<','<<y<<endl;
    int d1[limit] = {0,7,0,4,1,7,7,6};
    int d2[limit] = {0,7,2,0,1,9,6,9};
    cout<<"Original Array: "<<endl;
    show(d1,limit);
    show(d2,limit);
    swap1(d1,d2,limit);
    cout<<"After swap: "<<endl;
    show(d1,limit);
    show(d2,limit);
    return 0;
}

void show(int arr[], int n){
    cout<<arr[0]<<arr[1]<<'/';
    cout<<arr[2]<<arr[3]<<'/';
    for (int i = 4; i < n; i++)
    {   
        cout<<arr[i];
        /* code */
    }
    cout<<endl;
    

}
template <typename T>
void swap1 (T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;

}

template <typename T>
void swap1 (T a[], T b[], int n){
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    

}