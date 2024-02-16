#include "SALES.H"
#include<iostream>

namespace SALES{
    Sales::Sales(const double ar[], int n){
        int num = 4;
        double total = 0;
        max = 0;
        min = 99999999;
        for (int i = 0; i < QUARTERS; i++)
        {    
            sales[i] = 0;
    
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
            sales[i] = ar[i];
            total += sales[i];
        if (max < sales[i])
        {   
            max = sales[i];
            /* code */
        }
        if (min > sales[i])
        {   
            min = sales[i];
            /* code */
        }
        
        
        }
        average  = total/ num;
   

    }


    Sales::Sales(){
        using std::cout;
        using std::cin;
        using std::endl;
        for (int i = 0; i <4; i++)
            {   cout<<"Please enter quarter #"<<i<<"sale number: \n";
                while (!(cin>>sales[i]))
                {   
                    cin.clear();
                    while (cin.get() != '\n')
                        continue;
                    cout<<"Please enter a number.\n";
            
                }
                cin.get();
        
        /* code */
            }
        double total = 0;
        min = max = sales[0];
        for (int i = 0; i < 4; i++)
            {   
                total += sales[i];
                if (min>sales[i])
                {   
                    min = sales[i];
            
                }

                if (max < sales[i])
                {   
                    max = sales[i];
            
                }
       
            }
    
        average =total/4;
    }


    void Sales::showSales() const{
        using std::cout;
        for (int i = 0; i < 4; i++)
        {   
            cout<<"Quarter "<<i+1<<" sale number: "<<sales[i]<<std::endl;
        /* code */
        }
        cout<<"Max number: "<<max<<std::endl;
        cout<<"Minium number: "<<min<<std::endl;\
        cout<<"Average number: "<<average<<std::endl;

    }
}