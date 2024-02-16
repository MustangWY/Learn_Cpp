#include<iostream>
#include "SALES.H"

using namespace std;
using namespace SALES;

int main (void) {
    Sales sales1;
    double ar[3] = {400,500,400.33};
    Sales sales2(ar,3);
    sales1.showSales();
    sales2.showSales();


    return 0;
}