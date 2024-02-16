#include<iostream>
#include"SALES.h"
namespace SALES{
void setSales(Sales &s, const double ar[], int n){
   int num = 4;
   double total = 0;
    s.max = 0;
    s.min = 99999999;
   for (int i = 0; i < QUARTERS; i++)
   {    
        s.sales[i] = 0;
    /* code */
   }
   
   if (n<0)
   {    
        std::cout<<"Error"<<std::endl;
   }
   if (n<4)
   {
        num = n;
   }
   for (int i = 0; i < num; i++)
   {    
        s.sales[i] = ar[i];
        total += s.sales[i];
        if (s.max < s.sales[i])
        {   
            s.max = s.sales[i];
            /* code */
        }
        if (s.min > s.sales[i])
        {   
            s.min = s.sales[i];
            /* code */
        }
        
        
   }
    s.average = total / num;
   
    
}
void setSales(Sales& s){
    using std::cout;
    using std::cin;
    using std::endl;
    for (int i = 0; i <4; i++)
    {   cout<<"Please enter quarter #"<<i<<"sale number: \n";
        while (!(cin>>s.sales[i]))
        {   
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"Please enter a number.\n";
            /* code */
        }
        cin.get();
        
        /* code */
    }
    double total = 0;
    s.min = s.max = s.sales[0];
    for (int i = 0; i < 4; i++)
    {   
        total += s.sales[i];
        if (s.min>s.sales[i])
        {   
            s.min = s.sales[i];
            /* code */
        }

        if (s.max < s.sales[i])
        {   
            s.max = s.sales[i];
            /* code */
        }
        /* code */
    }
    
    s.average =total / 4;

    
}
void showSales(const Sales &s){
    using std::cout;
    for (int i = 0; i < 4; i++)
    {   
        cout<<"Quarter "<<i+1<<" sale number: "<<s.sales[i]<<std::endl;
        /* code */
    }
    cout<<"Max number: "<<s.max<<std::endl;
    cout<<"Minium number: "<<s.min<<std::endl;\
    cout<<"Average number: "<<s.average<<std::endl;
}
    
}