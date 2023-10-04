#include <iostream>
using namespace std;
int main(void){
    double arr[5]={10,20,30,40,50};
    double *pt=arr;
    cout<<"*pt = "<<*pt<<endl;
    cout<<"*++pt = "<<*++pt<<endl;//前缀运算符和取值运算符等级相同，从右往左与pt结合，++先于pt结合然后取值
    cout<<"*pt = "<<*pt<<endl;//此时pt指向第二个元素
    cout<<"++*pt = "<<++*pt<<endl;//取值运算符先与pt结合取出第二个元素20，然后与前缀++结合，得21
    cout<<"*pt = "<<*pt<<endl;//此时pt仍指向第二个元素值为21
    cout<<"(*pt)++ ="<<(*pt)++<<endl;//先取出第二个元素21，后缀++先打印，再加一，此时第二个元素为22
    cout<<"*pt = "<<*pt<<endl;//此时pt仍指向第二个元素值为22
    cout<<"*pt++ ="<<*pt++<<endl;//后缀等级高于取值，对pt进行后缀++，即先计算表达式再对pt加一，*pt++指向第二个元素，运算完成后pt指向第三个元素
    cout<<"*pt = "<<*pt<<endl;//此时pt指向第三个元素值为30
    return 0;
}