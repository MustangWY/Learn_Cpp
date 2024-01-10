#include<iostream>
using namespace std;
const int Len = 130;
const int Div = 7;
void subdivide(char ar[],int low,int high,int level);
int main(){
    char ruler[Len];
    int max, min;
    for (int  i = 0; i < Len; i++)
    {
        ruler[i]=' ';
    }
    ruler[Len-1]='\0';
    min = 0;
    max = Len-2;//字符串打印遇到\0才停止，前面将整个字符串置为空格，最后一位也为空格。这里将最后一位置为\0，将倒数第二位作为最高位。
    ruler[min]='|';
    ruler[max]='|';
    cout<<ruler<<endl;
    for (int i = 1; i <= Div; i++)
    {
        subdivide(ruler,min,max,i);
        cout<<ruler<<endl;
        for (int i = 1; i < Len-2; i++)
        {
            ruler[i]=' ';
        }
        
        /* code */
    }
    
    

    

    return 0;
}
void subdivide(char ar[],int low,int high,int level){
    int mid;
    if (level == 0)
        return;
    mid = (low+high)/2;
    ar[mid]='|';
    subdivide(ar,low,mid,level-1);
    subdivide(ar,mid,high,level-1);

}