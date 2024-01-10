#include<iostream>
using namespace std;
void show_array(const char * ar, int n = 0);
int num = 0;
int main(void){
    show_array("helloworld");
    show_array("Hallo", 1);
    return 0;
}

void show_array(const char * ar, int n ){
    //static int num = 0;//静态变量，无论调用多少次只会初始化一次
    num++;
    if (n == 0)
    {
        cout<<ar<<endl;
    } else {
        for (int i = 0; i < num; i++)
        {
            cout<<ar<<endl;
        }
        
    }
}
