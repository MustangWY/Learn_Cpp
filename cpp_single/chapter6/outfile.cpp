#include<fstream>       //1. include fstream ofstream           ifstream
#include <iostream>     //istraeam->cin      ostraeam->cout
int main(void){
    using namespace std;
    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;     //2.creat object of output file stream(ofstream).
    outFile.open("carinfo.txt"); //associate with a file.

    cout<<"enter the make and model of automobile: ";
    cin.getline(automobile,50);
    cout<<"enter the model year: ";
    cin>>year;
    cout<<"ebter the original asking price: ";
    cin>>a_price;
    d_price=a_price*0.913;

    //display information on screen with cout
    cout<<fixed;       //消除科学计数法
    cout.precision(2);  //显示小数点后两位
    cout.setf(ios_base::showpoint);//显示小数点和额外的零
    cout<<"Make and model: "<<automobile<<endl;
    cout<<"Year: "<<year<<endl;
    cout<<"Was asking: "<<a_price<<endl;
    cout<<"Now asking: "<<d_price<<endl;

    //do the same thing using outFile instead of cout
    outFile<<fixed;       
    outFile.precision(2);  
    outFile.setf(ios_base::showpoint);
    outFile<<"Make and model: "<<automobile<<endl;
    outFile<<"Year: "<<year<<endl;
    outFile<<"Was asking: "<<a_price<<endl;
    outFile<<"Now asking: "<<d_price<<endl;
    outFile.close();

    return 0;
}