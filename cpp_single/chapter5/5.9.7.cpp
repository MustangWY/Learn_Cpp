#include <iostream>
using namespace std;
const int Arrsize = 50;
struct car
{
    char manufacturer[Arrsize];
    int year;
};

int main(void){
    int num=0;
    cout<<"How many cars do you wish to catalog? ";
    cin>>num;
    cin.get();//输入数字之后回车还在输入流中
    car *cars = new car[num];
    for (int i = 0; i < num; i++)
    {
        cout<<"car#"<<i+1<<':';
        cout<<"Please enter the maker: ";
        cin.getline(cars[i].manufacturer,Arrsize);
        cout<<"Please enter the year made: ";
        cin>>cars[i].year;
        cin.get();
    }
    cout<<"Here is your collection: \n";
    for (int i = 0; i < num; i++)
    {   
        cout<<cars[i].year<<' '<<cars[i].manufacturer<<endl;
        /* code */
    }
    
    
    return 0;
}