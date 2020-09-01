#include <stdio.h>
// w = 1, b = 2
int white[8][8] = {
    {1, 2, 1, 2, 1, 2, 1, 2}, 
    {2, 1, 2, 1, 2, 1, 2, 1},
    {1, 2, 1, 2, 1, 2, 1, 2}, 
    {2, 1, 2, 1, 2, 1, 2, 1},
    {1, 2, 1, 2, 1, 2, 1, 2}, 
    {2, 1, 2, 1, 2, 1, 2, 1},
    {1, 2, 1, 2, 1, 2, 1, 2}, 
    {2, 1, 2, 1, 2, 1, 2, 1} };
int black[8][8] = {
    {2, 1, 2, 1, 2, 1, 2, 1},
    {1, 2, 1, 2, 1, 2, 1, 2}, 
    {2, 1, 2, 1, 2, 1, 2, 1},
    {1, 2, 1, 2, 1, 2, 1, 2}, 
    {2, 1, 2, 1, 2, 1, 2, 1},
    {1, 2, 1, 2, 1, 2, 1, 2}, 
    {2, 1, 2, 1, 2, 1, 2, 1},
    {1, 2, 1, 2, 1, 2, 1, 2} };
int board[50][50] = {0, };
int main() {
    int N, M;
    char check;
    int wnum, bnum;
    int min = 64;
    scanf("%d %d\n", &N, &M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M+1;j++){
            Loop: ;
            scanf("%c", &check);
            if(check == 'W'){
                board[i][j] = 1;
            }else if(check == 'B'){
                board[i][j] = 2;
            }else if(check == '\0'){
                goto Loop;
            }
        }
    }

    for(int i=0;i<N-7;i++){
        for(int j=0;j<M-7;j++){
            wnum = bnum = 0;
            for(int x=0;x<8;x++){
                for(int y=0;y<8;y++){
                    if(board[i+x][j+y] != white[x][y]){
                        wnum++;
                    }
                    if(board[i+x][j+y] != black[x][y]){
                        bnum++;
                    }
                }
            }
            if(min > wnum){
                min = wnum;
            }
            if(min > bnum){
                min = bnum;
            }
        }
    }

    printf("%d\n", min);
   return 0;

}