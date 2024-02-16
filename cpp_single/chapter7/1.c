#include<stdio.h>
#define PRINT(a) printf("%d\n",(a))

int main(void){

    int j,a[]={1,3,5,7,9,11,15,18,20}, *p = a+6;
        for ( j = 0; j < 5; j++)
           
            switch(j){
                case 4:PRINT(*(p--));
                break;
                case 3
                :PRINT(*(++p));
                break;
                case 2:PRINT(*(p++));
                break;
                case 1:PRINT(*(--p));
                break;
              
                default:p--;break;
            }
            /* code */
        
        
    return 0;
}