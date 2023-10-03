#include<iostream>
#include<cstring>
using namespace std;
int main (){
    int age;
    char grade;
    char name[20];
    cout<<"What is your first name ? ";
    cin.getline(name,20);
    char *first_name = new char[strlen(name)+1];
    strcpy(first_name,name);
    cout<<"What is your last name?";
    cin.getline(name,20);
    char *last_name = new char [strlen(name)+1];
    strcpy(last_name,name);
    cout<<"What letter grade do you deserve?";
    cin>>grade;
    grade=grade+1;
    cout<<"What is your age?";
    cin>>age;
    cout<<"Name: "<<last_name<<first_name<<endl;
    cout<<"Grade: "<<grade<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"test"<<endl;
    delete [] first_name;
    delete [] last_name;
    return 0;
}