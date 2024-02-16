#ifndef ___golf___
#define ___golf___
#include<string>

struct golf
{   
    std::string fullname;
    int handicap;
    /* data */
};

void setgolf(golf &g, const std::string name, int hc);
int setgolf(golf &g);
void handicap(golf & g, int hc);
void showgolf(const golf & g);


#endif