//const int *pt == int const *pt 
//int *const pt
//const int *const pt
#include<stdio.h>
int main(void){
    int n = 10;
    int m=100;
    //const int *pt=&n;//pt为只读指针，不能通过pt修改指向的对象，可以修改指针指向的位置
    int *pt=&n;
    const int *pd = &n;
    printf("n = %d\n",n);
    *pt=20;
    printf("n = %d\n",n);
    printf("*pd = %d\n",*pd);
    pd=&m;
    printf("*pd = %d\n",*pd);
    int *const pf = &n;//
    printf("*pf = %d\n",*pf);
    *pf=30;
    printf("*pf = %d\n",*pf);
    //pf=&m;出错，此时pf指针只能指向n，不能改变，但是可以改变指向对象的内容
    const int *const pa =&n;//只能指向n，且不可修改指向对象的内容。
    return 0;
}