#include<iostream>
#include<array>
#include<cctype>
using namespace std;
const int SIZE = 10;
int main(void){
    double donation[SIZE];
    //array<double,SIZE> donation;
    int i,count=0;
    double sum;
   for ( i ; i < SIZE; i++)
   {    
        cout<<"Please enter donation#"<<i+1<<':';
      if (!(cin>>donation[i]))
      {
        cin.clear();
        cout<<"Nonumeric detected, terminating......."<<endl;
        break;
      }  
      count++;
   }
   for ( i = 0; i < count; i++)
   {    
        sum+=donation[i];
   }
   cout<<fixed;
   cout.precision(2);
   cout.setf(ios_base::showpoint);
   cout<<"The average donation is "<<sum/count<<endl;
   int Count= 0;
   for ( i = 0; i < count; i++)
   {
        
        if (donation[i]>(sum/count))
        {
            Count++;
            /* code */
        }
        
    /* code */
   }
   cout<<"There are "<<Count<<" donations that is larger than average.";

    return 0;
}