#include<iostream>
using namespace std;
double* fill_array(double *pt,double *pd);
void show_array(const double *,const double *);
void reverse_array(double *begin,double *end);

int main(void){
    double arr[10];
    double*pt = fill_array(arr,arr+10);
    show_array(arr,pt);
    reverse_array(arr,pt);
    show_array(arr,pt);
 
    return 0;
}
double * fill_array(double *pt,double * pd){
    double* i = pt;
    cout<<"Please enter a number, q to quit. \n";
    for (i ; i!=pd; i++)
    {
        if (!(cin>>*(i)))
        {
            cout<<"quitting......\n";
            break;
        }else{
        cout<<"next: ";
        }
        
    }
    return i;

}
void show_array(const double* begin,const double * end){
    const double* i = begin;
    int j = 0;
    for (i,j; i !=end; i++,j++)
    {
        cout<<"Element #"<<" " << j+1 <<' '<<*(i)<<endl;
    }
    
}
void reverse_array(double *begin,double *end){
    double temp;
    double* i=begin;
    double* j=end-1;//结尾指针是指向数组最后一个元素后面的指针
    for (i,j; i<=j; i++,j--)
    {   
        temp = *(i);
        *(i)=*(j);
        *(j)=temp;
        /* code */
    }
    
}



