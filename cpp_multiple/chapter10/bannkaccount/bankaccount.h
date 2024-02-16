#ifndef __bankacc__
#define __bankacc__
class bankaccount
{
private:
    enum {CHARLEN = 50};
    char name[CHARLEN];
    char acc[CHARLEN];
    double money;
    /* data */
public:

    bankaccount(const char *pn = "NA",  const char * pa = "NA", double m = 0);
    ~bankaccount();
    void showAccount() const;
    void deposit(double m);
    void withdraw(double m);
};


#endif