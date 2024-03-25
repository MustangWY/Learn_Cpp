#include<cstdlib>
#include<iostream>
using namespace std;
int main(void){
    cout<<"Please enter feet number:\n";
    int feet = 0;
    cin>>feet;
    cin.get();
    cout<<"Please enter total number:\n";
    int total = 0;
    cin>>total;
    int chicken = 0,rabbits = 0;
    int j = 0;
    while((feet%2 != 0)){
        cout << "Wrong feet input,enter again:\n";
        cin>>feet;
        cin.get();
    }
    
    while(feet < total*2||feet>total*4)
    {   
        cout << "Wrong feet input, enter again:\n";
        cin>>feet;
        cin.get();
    }
 


    for(; j <= total; j++){
         if(j*2+(total-j)*4 == feet){
             break;
         }
     }
    chicken = j;
    rabbits = total - chicken;
    cout << "There are " << chicken <<
        " chicken and " << rabbits << "rabbits\n";
    return 0;
}
