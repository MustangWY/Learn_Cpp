#include<iostream>
#include<cstring>
using namespace std;
template<class T>
T Max(T ar[], int n);
template <>const char * Max<const char *>(const char *ar[], int n);
int main(void){
    int ar[6] = {11,55,444,89,77,9999};
    double arr[5] = {11.1,12.3,11.4,10.0};
    const char *ar3[5] = {
        "asgda",
        "sdadfa",
        "asdasdhad",
        "asdaadasa",
        "daa"                         /*上面的表达式中，等号右边的"hello"是一个不变常量，在c++中叫做string literal，type是const char *，
                                            而p则是一个char指针。如果强行赋值就是将右边的常量强制类型转换成一个指针，结果就是我们在修改一个const常量。*/
    };
    cout<<Max(ar,6)<<endl;
    cout<<Max(arr,4)<<endl;
    cout<<Max(ar3,5)<<endl;
    return 0;
}
template<class T>
T Max( T ar[], int n){
    for (int i = 0; i < n-1; i++)
    {   
        T temp;
       if (ar[i]>ar[i+1])
       {
            temp = ar[i];
            ar[i] = ar[i+1];
            ar[i+1] = temp;
       }
       
    }
    return ar[n-1];

}

template <> const char * Max< const char *>(  const char *ar[], int n){
        /*int length[n];
        for (int i = 0; i < n; i++)
        {   
            length[i]=strlen(ar[i]);
        }
        for (int i = 0; i < n; i++)
        {   
            for (int j = 1; j < n; j++)
            {   
                if (length[i]<=length[j])
                {
                    break;    //将第i个元素与数组内的元素比较，若有比它大的就停止比较，则第i个元素不是最大值。
                }
                return ar[i]; //得到最大值后即退出循环，返回第一个最大的字符串地址。
                
               
            }
        }
       */
      int pos = 0;
      for (int i = 1; i < n; i++)
      {
        if (strlen(ar[pos])<strlen(ar[i]))
        {   
            pos = i;
            /* code */
        }
        
      }
      return ar[pos];
}