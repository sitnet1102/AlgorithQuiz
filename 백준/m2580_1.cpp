// 스도쿠 채워질 때까지 돌아가는 방식으로 진행할 필요가 있음
// 큐를 이용해서 넣고 빼는 것을 반복 

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int v[81][2] = {{0,}};
vector <pair <int, int>> v1;
int M=0;

bool possible(int x, int y){
    //int check[10]={0,};
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
            if(board[x3 * 3 + j][y3 * 3 + i] == board[x][y]) {
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
    //if(k == M){
    if(sizeof(v1) == 0){
        //int Ans=0;
        /*
        for(int i=0;i<M;i++){
            if(board[v[i][0]][v[i][1]] == 0){
                return;
            }
        }
        */
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[j][i];
                if(j!=8){
                    cout << ' ';
                }
            }
            cout << '\n';            
        }
        //exit(0);
        return;
    }

    for(int i=1;i<=9;i++){
        board[v1[k].first][v1[k].second] = i;
        if(possible(v1[k].first, v1[k].second)){
            func(k+1);
            board[v1[k].first][v1[k].second] = 0;
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[j][i];
            if(!board[j][i]){
                pair<int, int> tmp;
                tmp.first = j;
                tmp.second = i;
                v1.push_back(tmp);
                /*
                v[M][0] = j;
                v[M][1] = i;
                M++;
                */
            }
        }
    }
    func(0);
    return 0;
}
