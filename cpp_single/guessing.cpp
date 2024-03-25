#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
int main(void){
    srand((unsigned)time(0));
    int num = rand()%100;
    cout<<"Please enter the number:\n";
    int enter;
    int times = 1;
    while(!(cin>>enter)){
        cin.clear();
        while(cin.get()!='\n')
                continue;
        cout<<"Please enter a number!\n";
    }
    while(enter != num){
        if (times >= 3){
            cout<<"chance ran out\n";
            return 0;
        }
        if(num >= enter){
            cout<<"Your guess is smaller than the number, guess again!\n";
            cin>>enter;
        
        }else{
             cout<<"Your guess is bigger than the number, guess again!\n";
        
         cin>>enter;
        
        }
 
       times++;
    
    
}
cout<<"Congradulations! You are right!.\n";
    return 0;
}
