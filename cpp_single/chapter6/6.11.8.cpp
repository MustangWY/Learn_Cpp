#include<iostream>
#include<fstream>
using namespace std;
int main(void){
    ifstream inFile;
    cout<<"enter the name of the file: ";
    char FileName[20];
    int count=0;
    cin.getline(FileName,20);
    char ch;
    inFile.open(FileName);
    if(!inFile.is_open()){
        cout<<"File not exist"<<endl;
        cout<<"Program terminating..."<<endl;
        exit(EXIT_FAILURE);
    }
    while (inFile.eof()==false)
    {

        inFile.get(ch);
        cout<<ch;
        count++;

    }
    cout<<"The file contains "<<count<<" characters."<<endl;
    




    return 0;
}