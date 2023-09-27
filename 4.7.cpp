#include<iostream>
using namespace std;
const int arrsize = 30;
struct pizza
{
    /* data */
    char corname[arrsize];
    double diameter;
    double weight;
};

int main(){
    //pizza p1={"",0,0};
    pizza *p1 = new pizza;
    cout<<"Please enter the following information: "<<endl;
    cout<<"name: ";
    //cin>>p1.corname;
    cin.getline(p1->corname,arrsize);
    cout<<"diameter: ";
    cin>>p1->diameter;
    //cin>>p1.diameter;
    cout<<"weight: ";
    cin>>p1->weight;
    //cin>>p1.weight;
    cout<<"Here is your pizza"<<endl;
    cout<<"name: "<<p1->corname<<endl;
    cout<<"diameter: "<<p1->diameter<<endl;
    cout<<"weight: "<<p1->weight<<endl; //4.7
    


    return 0;
}