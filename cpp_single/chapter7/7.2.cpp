#include<iostream>
using namespace std;
int fill_array(int ar[],int limit);
void show_array(int ar[],int n);
double cal_averge(int ar[],int n);
const int limit = 10;
int main(void){
    int grade[limit];
    int i = 0;
    double avg;
    i = fill_array(grade,limit);
    show_array(grade,i);
    avg = cal_averge(grade,i);
    cout<<"Your average score is "<<avg;
    return 0;
}
int fill_array(int ar[],int limit){
    int temp;
    cout<<"Please enter your score: (enter negative number to quit)\n";
    int i;
    for (i = 0; i < limit; i++)
    {   
       if(!(cin>>temp))                                                                                                      
        {
            cin.clear();
            while (cin.get()!='\n')
                continue;
            cout<<"Bad input ";
            i=-1;
            
        }else if (temp < 0)
        {
            break;
        }else ar[i] = temp;
        /* code */
    }
    return i;
}
void show_array(int ar[],int n){
    cout<<"Here are your scores: \n";
    for (int i = 0; i < n; i++)
    {   
        cout<<"score # "<<i+1<<" "<<ar[i]<<endl;
        /* code */
    }
    
}
double cal_averge(int ar[],int n){
    double sum;
    for (int i = 0; i < n; i++)
    {
        sum+=ar[i];
        
    }
    return sum/n;

    
}