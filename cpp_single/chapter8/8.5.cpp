#include<iostream>
using namespace std;
template<class T>
T Max5(T ar[5]);
int main(void){
    int ar[5] = {11,55,444,89,77};
    double arr[5] = {11.1,12.3,111.9,11.4,10.0};
    cout<<Max5(ar)<<endl;
    cout<<Max5(arr)<<endl;
    return 0;
}
template<class T>
T Max5(T ar[5]){
    for (int i = 0; i < 4; i++)
    {   
        T temp;
       if (ar[i]>ar[i+1])
       {
            temp = ar[i];
            ar[i] = ar[i+1];
            ar[i+1] = temp;
       }
       
    }
    return ar[4];

}