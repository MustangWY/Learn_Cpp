#include<iostream>
using namespace std;

struct chess
{   
    char display;
    int flag;
    /* data */
};

static chess map[10][10];


void initMap(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            map[i][j].display = ' ';
            map[i][j].flag = 0;
        }

    }
}

void showMap(){
    cout<<"  ";
    for(int i = 0; i < 10; i++){
        cout<<i<<' ';
    }
    cout<<endl;
    for(int i = 0; i < 10; i++){
        cout<<i<<'|';
        for(int j = 0; j < 10; j++){
            cout<<map[i][j].display<<'|';
        }
        cout<<"\n";
    }

}

void player(int i){
    cout<<"player"<<' '<<i<<" enter your choice:(x, y)";
    int x = 0, y = 0;
    cin>>x;
    cin.get();
    cin>>y;
    cin.get();
    if (i == 1)
    {   
        map[x][y].display = 'X';
        map[x][y].flag = 1;
        /* code */
    }else if (i == 2)
    {   
        map[x][y].display = 'O';
        map[x][y].flag = -1;
        /* code */
    }
    
    

}

int checkmate(){
    int winner = 0;
    int h = 0,v = 0,l = 0,r = 0;
    for (int i = 0; i < 10; i++)
    {   

        for(int j = 0; j < 5; j++)
        {   h = 0;                      //注意每次遍历表格将计数器置零
            for (int k = 0; k <= 5; k++)
            {
               if (map[i][j].flag==map[i][j+k].flag&&map[i][j].flag!=0)
               {
                    h++;
                    if (h == 5&&map[i][j].flag ==1)
                    {   
                       winner = 1;
                       return winner;
                        
                        /* code */
                    }else if(h == 5&&map[i][j].flag ==-1){
                        winner = 2;
                        return winner;
                    }
                    
                /* code */
               }
                
            }
        }
        /* code */
    }

     for (int i = 0; i <= 5; i++)
    {   
        for(int j = 0; j < 10; j++)
        {   v = 0;
            for (int k = 0; k <= 4; k++)
            {
               if (map[i][j].flag==map[i+k][j].flag&&map[i][j].flag!=0)
               {
                    v++;
                    if (v == 5&&map[i][j].flag ==1)
                    {   
                       winner = 1;
                       return winner;
                        
                        /* code */
                    }else if(v == 5&&map[i][j].flag ==-1){
                        winner = 2;
                        return winner;
                    }
                /* code */
               }
                
            }
        }
        /* code */
    }
    
     for (int i = 0; i <= 5; i++)
    {   
        for(int j = 0; j <= 5; j++)
        {   r = 0;
            for (int k = 0; k <= 4; k++)
            {
               if (map[i][j].flag==map[i+k][j+k].flag&&map[i][j].flag!=0)
               {
                    r++;
                    if (r == 5&&map[i][j].flag ==1)
                    {   
                       winner = 1;
                       return winner;
                        
                        /* code */
                    }else if(r == 5&&map[i][j].flag ==-1){
                        winner = 2;
                        return winner;
                    }
                /* code */
               }
                
            }
        }
        /* code */
    }

    for (int i = 4; i < 10; i++)
    {   
        for(int j = 0; j <= 5; j++)
        {   l = 0;
            for (int k = 0; k <= 4; k++)
            {
               if (map[i][j].flag==map[i-k][j+k].flag&&map[i][j].flag!=0)
               {
                    l++;
                    if (l == 5&&map[i][j].flag ==1)
                    {   
                       winner = 1;
                       return winner;
                        
                        /* code */
                    }else if(l == 5&&map[i][j].flag ==-1){
                        winner = 2;
                        return winner;
                    }
                /* code */
               }
                
            }
        }
        /* code */
    }
    return winner;

}

int main(void){
    initMap();
    showMap();
    int winner = 0;
    while (!winner)
    {   
        player(1);
        player(2);
        showMap();
        winner = checkmate(); 
    }
    cout<<"Player "<<winner<<" won! "<<endl;
    return 0;
}