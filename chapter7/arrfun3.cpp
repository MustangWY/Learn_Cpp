#include<iostream>
using namespace std;
int fill_array(double arr[], int size);
const int Max = 5;
void show_array(const double arr[],int size);
void revalue(double factor,double arr[],int size);
int main (void){
    int count;
    double properties[Max];
    count = fill_array(properties,Max);
    show_array(properties,count);
    if (count>0)
        {
            cout<<"Enter revaluation factor: ";
            double factor;
            while (!(cin>>factor))
            {   
                cin.clear();
                while (cin.get()!='\n')
                {
                    continue;
                }
                cout<<"Bad input, enter again.";
                /* code */
            }
            revalue(factor,properties,count);
            show_array(properties,count);
        }
    

    return 0;
}
int fill_array(double arr[],int size){
    int i = 0;
    double temp;
    for ( i ; i < size; i++)
    {
        cout<<"Enter value# "<<i+1<<": ";
         cin>>temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get()!='\n')
            {   
                continue;
            }
            cout<<"Bad input,terminating....."<<endl;
            break;
            /* code */
        }else if (temp<0)
            break;  
        arr[i]=temp;
    }
    return i;
    
}
void show_array(const double arr[],int size){//const表明不能通过该指针修改指向的对象
    for (int i = 0; i < size; i++)
    {
        cout<<"Property #"<<i+1<<" $"<<arr[i]<<endl;
        /* code */
    }
    
}
void revalue(double factor,double arr[],int size){
    for (int i = 0; i < size; i++)
    {
        arr[i]=arr[i]*factor;
    }
    
}