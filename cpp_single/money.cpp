#include<iostream>
using namespace std;
int main(void){
    int count;
    int sum;
    int two = 0, five = 0;
    for ( five ; five <= 10/5; five++)
    {   
        for ( two; two <= 10/2; two++)
        {   
            int n = 10 - five * 5 - two * 2;
            sum = five * 5 + two * 2 +n;
            if (sum == 10&&n >= 0)
            {   
                count++;
                cout<<five<<" five yuans "
                    <<two<<" two yuans "
                    <<n<<" one yuans"<<endl;
                /* code */
            }
            
            
            /* code */
        }
        two = 0;
        
        /* code */
    }
    

    return 0;
}