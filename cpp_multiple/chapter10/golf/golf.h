#ifndef __GOLF__
#define __GOLF__
class golf
{
private:
    enum{Length = 40};
    char fullname[Length];
    int handicap;
    /* data */
public:
    golf(const char * name = "NA", int hc = 0);
    
    void setgolf();
    void ShowGolf() const;
    void SetHandicap(int hc);
};


#endif