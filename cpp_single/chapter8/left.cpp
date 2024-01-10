#include <iostream>
const int ArSize = 80;
using namespace std;
char *left(const char*str,int n =1);
unsigned long left(unsigned long num , unsigned ct);
int main(void){
    char sample[ArSize];
    cout<< "enter a string. "<<endl;
    cin.get(sample,ArSize);
    unsigned long n = 12345678;
    char *temp;
    for (int i = 0; i < 10; i++)
    {   
        cout<<left(n,i)<<endl;
        temp = left(sample, i);
        cout<<temp<<endl;
        delete [ ] temp;
        /* code */
    }
    
    /*char *ps = left(sample,4);
    cout<<ps<<endl;
    delete [] ps;
    ps = left(sample);
    cout<<ps<<endl;
    delete [] ps;
    return 0;*/
    return 0;
}


unsigned long left(unsigned long num , unsigned ct){
    int digit = 1;
    unsigned long n = num;
    if (ct == 0 || num == 0)
    {   
        return 0;
        /* code */
    }
    
    while (n/=10)
    {
        digit++;
    }
    if (digit>ct)
    {
        ct = digit - ct;
        while (ct--)
        {   
            num/=10;
            
 
            /* code */
        }
        return num;
    }
    else return num;
    
    


}

char *left(const char*str,int n){//默认参数写在函数原型上，定义里面不要写

    if (n<0)
    {
        n = 0;
    }
    
   /*** char *pt = new char[n+1];
    int i;
   for (i = 0; i < n&&str[i]!='\0'; i++)
   {    
        pt[i] = str[i];
       
    
   }
   while (i<=n)
        {
            pt[i++] = '\0';
        }
   
    ***/
   int m = 0;
   while (m<n&&str[m]!='\0')
   {
       m++;
   }
   char*pt = new char[m+1];
   for (int i = 0; i < m; i++)
   {
        pt[i] = str[i];
    /* code */
   }
   pt[m] = '\0';
   
    return pt;
}