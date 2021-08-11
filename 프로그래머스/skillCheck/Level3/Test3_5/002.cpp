#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> v;
vector<int> cost;
int N;
int cur_dir = 0;
int dir[4][2] = {
    {1, 0}, {0. 1}, {-1, 0}, {0, -1}
};

void dfs(int x, int y){
    if(x==N && y==N){

        return;
    }
    for(int i=0;i<3;i++){

    }
}



int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<int> wall;
    N = board.size();
    //v = board;
    for(int i=0;i<2 + board.size();i++){
        wall.push_back(1);
    }
    v.push_back(wall);
    for(int i=0;i<board.size();i++){
        vector<int> tmp;
        tmp.push_back(1);
        for(int j=0;j<board[i].size();j++){
            tmp.push_back(board[i][j]);
        }
        tmp.push_back(1);
        v.push_back(tmp);
    }
    v.push_back(wall);


    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << N;

    return answer;
}