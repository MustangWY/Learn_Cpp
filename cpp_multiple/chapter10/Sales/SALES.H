#ifndef ___sales___
#define ___sales___

namespace SALES{
   class Sales
   {
   private:
    enum {QUARTERS = 4};
    double sales[QUARTERS];
    double average;
    double min;
    double max;
    /* data */
   public:
    Sales(const double ar[], int n);
    Sales();
    void showSales() const;
   }; 
}

#endif