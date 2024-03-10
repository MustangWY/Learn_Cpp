//五子棋代码
#include<stdio.h>

//全局地图
char map[10][10];
//初始化地图 将数组中的每个元素都赋值未空格字符
void initMap(void){
    int i,j;
    for(i = 0;i < 10;i++){
        for(j = 0;j < 10;j++){
            map[i][j] = ' ';
        }
    }
}
//显示地图 
void showMap(void){
    int i,j;
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for(i = 0;i < 10;i++){
        printf("%d ",i);
        for(j = 0;j < 10;j++){
            printf("|%c",map[i][j]);
        }
        printf("|\n");
    }
}

//判断胜负 返回1,表示胜利 
int check(int row,int col){
    char k = map[row][col];
    int h = 1,z = 1,lr = 1,rl = 1;
    //水平
    //水平向左
    for(int i = 1;i <= 5;i++){
        if(col - i >= 0 && map[row][col - i] == k){
            h++;
        }else{
            break;
        }
    }
    //水平向右
    for(int i = 1;i <= 5;i++){
        if(col + i <= 9 && map[row][col + i] == k){
            h++;
        }else{
            break;
        }
    }
    if(h >= 5){
        return 1;
    }

    //竖直
    //竖直向上
    for(int i = 1;i <= 5;i++){
        if(row - i >= 0 && map[row - i][col] == k){
            z++;
        }else{
            break;
        }
    }
    //竖直向下
    for(int i = 1;i <= 5;i++){
        if(row + i <= 9 && map[row + i][col] == k){
            z++;
        }else{
            break;
        }
    }
    if(z >= 5){
        return 1;
    }
    //左上到右下
    //向左上
    for(int i = 1;i <= 5;i++){
        if(row - i >= 0 && col - i >= 0 && map[row - i][col - i] == k){
            lr++;
        }else{
            break;
        }
    }
    //向右下
    for(int i = 1;i <= 5;i++){
        if(row + i <= 9 && col + i <= 9 && map[row + i][col + i] == k){
            lr++;
        }else{
            break;
        }
    }
    if(lr >= 5){
        return 1;
    }
    
    //右上到左下
    //向右上
    for(int i = 1;i <= 5;i++){
        if(row - i >= 0 && col + i <= 9 && map[row - i][col + i] == k){
            rl++;
        }else{
            break;
        }
    }
    //向左下
    for(int i = 1;i <= 5;i++){
        if(row + i <= 9 && col - i >= 0 && map[row + i][col - i] == k){
            rl++;
        }else{
            break;
        }
    }
    if(rl >= 5){
        return 1;
    }

    return 0;
}


//下棋
void play(void){
    int row,col;
    int count = 0;
    for(;;){
        if(count % 2 == 1){
            //白子下棋  以 'O' 做棋子
            printf("白子下棋:\n");
            printf("请输入横坐标:");
            scanf("%d",&row);
            printf("请输入纵坐标:");
            scanf("%d",&col);
            if(0 <= row && row <= 9 && 0 <= col && col <= 9 && map[row][col] == ' '){
                map[row][col] = 'O';
                //重新显示地图
                showMap();
                count++;
                if(check(row,col) == 1){
                    printf("白棋胜利!\n");
                    break;
                }
            }else{
                printf("位置非法或者该位置已有棋子,请重新落子\n");
            }
        }else{
            //黑子下棋
            printf("黑子下棋:\n");
            printf("请输入横坐标:");
            scanf("%d",&row);
            printf("请输入纵坐标:");
            scanf("%d",&col);
            if(0 <= row && row <= 9 && 0 <= col && col <= 9 && map[row][col] == ' '){
                map[row][col] = 'X';
                //重新显示地图
                showMap();
                count++;
                if(check(row,col) == 1){
                    printf("黑棋胜利\n");
                    break;
                }
            }else{
                printf("位置非法或者该位置已有棋子,请重新落子\n");
            }
        }
        
        //判断棋盘是否落满
        if(count == 100){
            printf("棋盘落满,双方和棋\n");
            break;
        }
    }
}


int main(void){
    initMap(); 
    showMap();
    play();
    return 0;
}











