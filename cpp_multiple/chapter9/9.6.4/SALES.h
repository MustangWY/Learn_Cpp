#ifndef ___sales___
#define ___sales___

namespace SALES{
    const int QUARTERS = 4;
    struct Sales
    {   
        double sales[QUARTERS];
        double average;
        double max;
        double min;
        /* data */
    };
    void setSales(Sales &s, const double ar[], int n);
    void setSales(Sales& s);
    void showSales(const Sales &s);
    

}

#endif