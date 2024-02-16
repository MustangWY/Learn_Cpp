#include<iostream>
#include"SALES.h"

using namespace std;
using namespace SALES;
int main (void) {

    Sales sales1;
    Sales sales2;
    setSales(sales1);
    double ar [3] = {100.1,200.2,300.3};
    setSales(sales2, ar, 3);
    showSales(sales1);
    showSales(sales2);
    return 0;
}