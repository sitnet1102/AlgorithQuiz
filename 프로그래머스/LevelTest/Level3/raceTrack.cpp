#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board) {
    vector<vector<int>> v;
    queue<vector<int>> q;
    //vector<int> zero;
    int N;
    int answer = 0;
    int d[4][2] = {
        {1, 0}, 
        {0, 1}, 
        {-1, 0}, 
        {0, -1}
    };
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
    cout << N << "\n";
    for(int i=0;i<4;i++){
        cout << d[i][0] << " " << d[i][1] << "\n";
    }
    /*
    zero.push_back(0);  // dir
    zero.push_back(1);  // x
    zero.push_back(1);  // y
    q.push(zero);
    */
    q.push({0,1,1});
    while(!q.empty()){
        vector<int> front = q.front();
        vector<int> tmp;
        int dir, x, y;

        for(int i=0;i<4;i++){
            dir = (i + front[0]) / 4;
            
            q.push({dir, x, y});
        }

        /*
        tmp.push_back(dir);
        tmp.push_back(x);
        tmp.push_back(y);
        q.push(tmp);
        */

    }


    return answer;
}