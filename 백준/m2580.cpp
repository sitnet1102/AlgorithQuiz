/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
반례 
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int board[9][9];
int v[81][2] = {{0,}};
int M=0;

bool possible(int x, int y){
    int check[10]={0,};
    int width = 0;  // 가로
    int depth = 0;  // 세로
    int sqaure = 0;
    int x3 = x/3;
    int y3 = y/3;

    for(int i=0;i<9;i++){
        // 가로
        if(board[i][y] == board[x][y]){
            width ++;
        }
        // 세로
        if(board[x][i] == board[x][y]){
            depth ++;
        }
    }
    // 사각형 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[x3 * 3 + j+1][y3 * 3 + i+1] == board[x][y]) {
                sqaure ++;
            }
        }
    }
    
    if(width == 2 || depth == 2 || sqaure == 2){
        return false;
    }

    return true;
}

void func(int k){
    if(k == M){
        //int Ans=0;
        for(int i=0;i<M;i++){
            if(board[v[i][0]][v[i][1]] == 0){
                return;
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[j][i];
                if(j!=8){
                    cout << ' ';
                }
            }
            cout << '\n';            
        }
        exit(0);
        return;
    }

    for(int i=1;i<=9;i++){
        board[v[k][0]][v[k][1]] = i;
        if(possible(v[k][0], v[k][1])){
            func(k+1);
            board[v[k][0]][v[k][1]] = 0;
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[j][i];
            if(!board[j][i]){
                v[M][0] = j;
                v[M][1] = i;
                M++;
            }
        }
    }
    func(0);
    return 0;
}
