#include<iostream>
using namespace std;
struct job
{   
    char name[40];
    double salary;
    int floor;
    /* data */
};
void show(job& j);
template <typename T>
void swap1 (T &a, T &b);
void swap1(int a, int b);
template<> void swap1<job>(job &j1, job &j2);
template void swap1<int>(int &a, int &n);
int main(void){
    job sue = {"Susan Yafee",73000.60,7};
    job sidney = {"Sidney Taffee", 78060.72,9};
    int i = 10;
    int j = 20;
    cout<<"i,j = "<<i<<','<<j<<endl;
    swap1(i,j);//非模板函数优先级最高，显示具体化函数次之，常规模板最低
    cout<<"After swap, i,j = "<<i<<','<<j<<endl;
    double x = 22.0;
    double y = 11.1;
    cout<<"x,y = "<<x<<','<<y<<endl;
    swap1(x,y);
    cout<<"After swap, x,y = "<<x<<','<<y<<endl;

    cout<<"Before job swapping: "<<endl;
    show(sue);
    show(sidney);
    swap1(sue,sidney);
    cout<<"After swapping sue and sidney: "<<endl;
    show(sue);
    show(sidney);
    

    return 0;
}
template <typename T>
void swap1 (T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;

}

void show(job& j){
    cout<<j.name<<": "<<j.salary<<" on floor "<<j.floor<<endl;

}
//显示具体化函数：
template<> void swap1<job>(job &j1, job &j2){
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}
//常规函数：

void swap1(int a, int b){

    int temp;
    temp = a;
    a = b;
    b = temp;
    cout<<"Hello world "<<"a = "<<a<<" b = "<<b<<endl;
}



    
