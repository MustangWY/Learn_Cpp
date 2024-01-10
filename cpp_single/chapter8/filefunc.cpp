#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
const int limit = 5;
void file_it(ostream &os,double fo,const double fr[],int n);
int main (void){
    fstream fout;
    const char *fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout<<"Cant open"<<endl;
        exit(EXIT_FAILURE);
    }
    double objective;
    cout<<"Enter the focal length of your telescope objective is mm: ";
    cin>>objective;
    double eps  [limit];
    for (int i = 0; i < limit; i++)
    {
        cout<<"Eyepieces #"<<i+1<<" : ";
        cin>>eps[i];
    }
    file_it(cout,objective,eps,limit);
    file_it(fout,objective,eps,limit);
    cout<<"Done.\n";
    return 0;
}

void file_it(ostream &os,double fo,const double fr[],int n){//基类引用指向基类德对象和派生类的对象
    os<<"Focal length of objective: "<<fo<<endl;
    os<<"F.1. eyepieces "<<"magnification "<<endl;
    for (int i = 0; i < n; i++)
    {   
        os<<"     "<<fr[i]<<"           "<<int(fo/fr[i]+0.5)<<endl;
        /* code */
    }
    

}