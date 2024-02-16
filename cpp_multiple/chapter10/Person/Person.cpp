#include<iostream>
#include"Person.h"
Person::Person(const std::string & lb, const char* fn ){
    lname = lb;
    int i = 0;
    while ((*fn) && i < 50)
    {   
        fname[i] = *fn;
        fn++;
        i++;
        /* code */
    }
}
void Person::show() const{
    using std::cout;
    cout<<fname<<' '<<lname<<std::endl;
}
void Person::FormalShow() const{
    std::cout<<lname<<' '<<fname<<std::endl;
}
