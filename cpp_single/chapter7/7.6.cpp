#include<iostream>
using namespace std;
int fill_array(double ar[],int n);
void show_array(const double ar[],int n);
void reverse_array(double ar[],int n);
int main(void){
    double arr[10];
    int i = fill_array(arr,10);
    show_array(arr,i);
    reverse_array(arr,i);
    show_array(arr,i);
    return 0;
}
int fill_array(double ar[],int n){
    int i = 0;
    cout<<"Please enter a number, q to quit. \n";
    for (i ; i < n; i++)
    {
        if (!(cin>>ar[i]))
        {
            cout<<"quitting......\n";
            break;
        }else{
        cout<<"next: ";
        }
        
    }
    return i;

}
void show_array(const double ar[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"Element #"<<" " << i+1 <<' '<<ar[i]<<endl;
    }
    
}
void reverse_array(double ar[],int n){
    double temp;
    for (int i = 0; i <= n/2; i++)
    {   
        temp = ar[i];
        ar[i]=ar[n-i-1];
        ar[n-i-1]=temp;
        /* code */
    }
    
}