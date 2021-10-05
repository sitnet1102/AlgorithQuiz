#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
bool cmp2(vector<vector<int>> a, vector<vector<int>> b){
    return a[0][0] < b[0][0];
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<int>> boardIsused;
    vector<vector<int>> tableIsused;
    
    vector<vector<vector<int>>> blank;
    vector<vector<vector<int>>> block;
    
    for(int i=0;i<game_board.size();i++){
        vector<int> tmp;
        for(int j=0;j<game_board[i].size();j++){
            tmp.push_back(0);
        }
        boardIsused.push_back(tmp);
    }
    
    for(int i=0;i<table.size();i++){
        vector<int> tmp;
        for(int j=0;j<table[i].size();j++){
            tmp.push_back(0);
        }
        tableIsused.push_back(tmp);
    }
    
    for(int i=0;i<game_board.size();i++){
        for(int j=0;j<game_board[i].size();j++){
            queue<vector<int>> q;
            vector<vector<int>> nodes;
            vector<int> S;
            S.push_back(0);
            nodes.push_back(S);
            vector<int> cur;
            if(!boardIsused[i][j]){
                boardIsused[i][j] = 1;
                if(!game_board[i][j]){
                    cur.push_back(i);
                    cur.push_back(j);
                    q.push(cur);
                }
            }
            while(!q.empty()){
                vector<int> tmp = q.front();
                nodes.push_back(tmp);
                nodes[0][0] ++ ;
                q.pop();
                if(tmp[0] - 1 >= 0){
                    if(!boardIsused[tmp[0]-1][tmp[1]] && !game_board[tmp[0]-1][tmp[1]]){
                        vector<int> a;
                        boardIsused[tmp[0]-1][tmp[1]] = 1;
                        a.push_back(tmp[0]-1);
                        a.push_back(tmp[1]);
                        q.push(a);
                    }
                }
                if(tmp[0] + 1 < game_board.size()){
                    if(!boardIsused[tmp[0]+1][tmp[1]] && !game_board[tmp[0]+1][tmp[1]]){
                        vector<int> a;
                        boardIsused[tmp[0]+1][tmp[1]] = 1;
                        a.push_back(tmp[0]+1);
                        a.push_back(tmp[1]);
                        q.push(a);
                    }
                }
                if(tmp[1] - 1 >= 0){
                    if(!boardIsused[tmp[0]][tmp[1]-1] && !game_board[tmp[0]][tmp[1]-1]){
                        vector<int> a;
                        boardIsused[tmp[0]][tmp[1]-1] = 1;
                        a.push_back(tmp[0]);
                        a.push_back(tmp[1]-1);
                        q.push(a);
                    }
                }
                if(tmp[1] + 1 < game_board.size()){
                    if(!boardIsused[tmp[0]][tmp[1]+1] && !game_board[tmp[0]][tmp[1]+1]){
                        vector<int> a;
                        boardIsused[tmp[0]][tmp[1]+1] = 1;
                        a.push_back(tmp[0]);
                        a.push_back(tmp[1]+1);
                        q.push(a);
                    }
                }
            }
            if(nodes[0][0] != 0){
                blank.push_back(nodes);
            }
        }
    }
    
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table[i].size();j++){
            queue<vector<int>> q;
            vector<vector<int>> nodes;
            vector<int> S;
            S.push_back(0);
            nodes.push_back(S);
            vector<int> cur;
            if(!tableIsused[i][j]){
                tableIsused[i][j] = 1;
                if(table[i][j]){
                    cur.push_back(i);
                    cur.push_back(j);
                    q.push(cur);
                }
            }
            while(!q.empty()){
                vector<int> tmp = q.front();
                nodes.push_back(tmp);
                nodes[0][0] ++ ;
                q.pop();
                if(tmp[0] - 1 >= 0){
                    if(!tableIsused[tmp[0]-1][tmp[1]] && table[tmp[0]-1][tmp[1]]){
                        vector<int> a;
                        tableIsused[tmp[0]-1][tmp[1]] = 1;
                        a.push_back(tmp[0]-1);
                        a.push_back(tmp[1]);
                        q.push(a);
                    }
                }
                if(tmp[0] + 1 < table.size()){
                    if(!tableIsused[tmp[0]+1][tmp[1]] && table[tmp[0]+1][tmp[1]]){
                        vector<int> a;
                        tableIsused[tmp[0]+1][tmp[1]] = 1;
                        a.push_back(tmp[0]+1);
                        a.push_back(tmp[1]);
                        q.push(a);
                    }
                }
                if(tmp[1] - 1 >= 0){
                    if(!tableIsused[tmp[0]][tmp[1]-1] && table[tmp[0]][tmp[1]-1]){
                        vector<int> a;
                        tableIsused[tmp[0]][tmp[1]-1] = 1;
                        a.push_back(tmp[0]);
                        a.push_back(tmp[1]-1);
                        q.push(a);
                    }
                }
                if(tmp[1] + 1 < table.size()){
                    if(!tableIsused[tmp[0]][tmp[1]+1] && table[tmp[0]][tmp[1]+1]){
                        vector<int> a;
                        tableIsused[tmp[0]][tmp[1]+1] = 1;
                        a.push_back(tmp[0]);
                        a.push_back(tmp[1]+1);
                        q.push(a);
                    }
                }
            }
            if(nodes[0][0] != 0){
                block.push_back(nodes);
            }
        }
    }
    for(int i=0;i<blank.size();i++){
        sort(blank[i].begin()+1,blank[i].end(),cmp);
    }
    for(int i=0;i<block.size();i++){
        sort(block[i].begin()+1,block[i].end(),cmp);
    }
    sort(blank.begin(),blank.end(),cmp2);
    sort(block.begin(),block.end(),cmp2);
    for(int i=0;i<blank.size();i++){
        for(int j=0;j<blank[i].size();j++){
            for(int k=0;k<blank[i][j].size();k++){
                cout << blank[i][j][k] << " ";
            }
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i=0;i<block.size();i++){
        for(int j=0;j<block[i].size();j++){
            for(int k=0;k<block[i][j].size();k++){
                cout << block[i][j][k] << " ";
            }
            cout << " ";
        }
        cout << "\n";
    }
    return answer;
}