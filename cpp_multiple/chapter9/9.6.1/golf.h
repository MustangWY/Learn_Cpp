#ifndef ___golf___
#define ___golf___

const int Len = 40;
struct golf
{   
    char fullname[Len];
    int handicap;
    /* data */
};

void setgolf(golf &g, const char * name, int hc);
int setgolf(golf &g);
void handicap(golf & g, int hc);
void showgolf(const golf & g);


#endif