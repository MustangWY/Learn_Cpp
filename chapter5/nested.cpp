#include <iostream>
using namespace std;
const int cities = 5;
const int years = 4;
int main(void){
    const char * city[cities] = {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"

    };
    int maxtemps[years][cities]={
        {96,100,87,101,105},
        {96,98,91,107,104},
        {97,101,93,108,107},
        {98,103,95,109,108}
    };
    cout<<"Here are the temperature of five cities in four years: "<<endl;

    for (int i = 0;i<cities;i++){
        cout<<city[i]<<" :\t";
        for (int j = 0;j<years;j++){
            cout<<maxtemps[j][i]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}