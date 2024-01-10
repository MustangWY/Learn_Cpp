#include<iostream>
using namespace std;
const int ArrSize = 50;
struct CandyBar
{   
    char name[ArrSize];
    double weight;
    int calorie;
    /* data */
};
void SetCandy (CandyBar &ca,const char * pt = "Millennium Munch", double wei = 2.85, int cal = 350);
void ShowCandy (const CandyBar & ca);

int main(void){
    CandyBar ca = {
        "abc",
        20.5,
        100
    };
    SetCandy(ca);
    ShowCandy(ca);
    return 0;
}

void SetCandy (CandyBar &ca,const char * pt , double wei , int cal){
    int i = 0;
    while (*pt)
        {
            ca.name[i] = *pt;
            if (i>=ArrSize)
            {
                ca.name[i-1] = '\0';
                break;
            }
            i++;
            pt++;
        }
   ca.calorie = cal;
   ca.weight = wei;
}


void ShowCandy (const CandyBar & ca){
    cout<<"Candy name: "<<ca.name<<endl;
    cout<<"Candy weight: "<<ca.weight<<endl;
    cout<<"Candy calorie: "<<ca.calorie;

}