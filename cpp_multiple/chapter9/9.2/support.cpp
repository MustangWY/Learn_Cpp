#include"support.h"
using namespace std;
void update(double dt){
    warming +=dt;   //更新全局变量
    cout<<"Updating global warming "<<warming;
    cout<<" Degrees. \n";

}


void local(void){
    double warming = 0.8 ;//新变量会将外部变量隐藏
    cout<<"Local warming is "<<warming<<" degrees."<<endl; 
    cout<<"But global warming is "<<::warming<<" degrees."<<endl;

}
