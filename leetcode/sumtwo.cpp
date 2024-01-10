#include <iostream>
using namespace std;
const int Max = 50;
int* twoSum( int ar[],int limit, int target);
int main (void){
    int arr[Max]={};
    int target,count;
    cout<<"Please enter nums,enter q to stop";
    for (int i = 0; i < 5; i++)
    {
        
      while (!(cin>>arr[i]))
      {
            cin.clear();
            while (cin.get()!='\n')
            {
                continue;
            }
            cout<<"Bad input.";
            break;
              
      }
      count++;
    }
      cout<<"Please enter target:";
      cin>>target;
      int *pd;
      pd = twoSum(arr,count,target);
      cout<<"Here are the results:"<<*pd <<" and "<<*(pd+1);
      delete pd;
    return 0;

}
int* twoSum( int ar[],int limit, int target)
{   

    int *pt = new int[2];

    for (int i = 0; i < limit; i++)
    {   
        if (ar[i]+ar[i+1]==target)
        {
            pt[0]=i;
            pt[1]=i+1;
            break;
        }
        
        /* code */
    }
    return pt;

    
}