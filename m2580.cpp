#include <stdio.h>
#include <iostream>

using namespace std;

int board[9][9];
int v[81][2];
int M=0;

bool possible(int x, int y){
    // 가로

    // 세로

    // 사각형 

    
}

void func(int k){
    if(k == M){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[j][i];
            }
        }
    }

    for(int i=1;i<=9;i++){
        board[v[k][0]][v[k][1]] = i;
        if()
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[j][i];
            if(!board[j][i]){
                M++;
            }
        }
    }
    func(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[j][i];
        }
    }
    return 0;
}
