#include <iostream>
using namespace std;
int main(){
    int*ps=new int;
    *ps=1001;
    int*pq = ps;
    cout<<"*ps: "<<*ps<<endl;
    cout<<"*pq: "<<*pq<<endl;
    delete pq;
    cout<<"*ps: "<<*ps<<endl;
    cout<<"*pq: "<<*pq<<endl;
    double* p3=new double [3];
    p3[0]=1;
    p3[1]=2;
    p3[2]=3;
    for(int i=0;i<3;i++){
        cout<<"p3"<<i<<"="<<p3[i]<<endl;
    }
    p3=p3+1;
    cout<<p3[1]<<endl;
    cout<<p3[2]<<endl;
    p3=p3-1;
    cout<<p3[2]<<endl;
    cout<<"ps = "<<ps<<endl;
    cout<<"&ps = "<<&ps;
    delete []p3;
    return 0;
}