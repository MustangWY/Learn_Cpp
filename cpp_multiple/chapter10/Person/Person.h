#ifndef __PERSON__
#define __PERSON__
#include<string>
class Person{
    private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
    public:
    Person(){lname = ""; fname[0] = '\0';}
   
    Person(const std::string & lb, const char* fn = "Heyyou");
    void show() const;
    void FormalShow() const;

};




#endif