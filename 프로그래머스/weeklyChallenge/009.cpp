#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> v;
    vector<int> isused;
    
    for(int i=0;i<=n;i++){
        vector<int> tmp;
        v.push_back(tmp);
    }
    
    for(int i=0;i<wires.size();i++){
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=0;i<=n;i++){
        isused.push_back(0);
    }
    /*
    for(int i=0;i<v.size();i++){
        cout << i << "   --   ";
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for(int i=0;i<wires.size();i++){
        vector<vector<int>> vertex = v;
        vector<int> x = wires[i];
        vector<int> isused_tmp = isused;
        vector<int> half;
        queue<int> q;
        int a;
        for(int j=0;j<vertex[x[0]].size();j++){
            if(x[1] == vertex[x[0]][j]){
                vertex[x[0]].erase(vertex[x[0]].begin() + j);
            }
        }
        for(int j=0;j<vertex[x[1]].size();j++){
            if(x[0] == vertex[x[1]][j]){
                vertex[x[1]].erase(vertex[x[1]].begin() + j);
            }
        }
        q.push(1);
        while(!q.empty()){
            int Num = q.front();
            q.pop();
            if(!isused_tmp[Num]){
                half.push_back(Num);
            }
            isused_tmp[Num] = 1;
            for(int k=0;k<vertex[Num].size();k++){
                if(!isused_tmp[vertex[Num][k]]){
                    q.push(vertex[Num][k]);
                }
            }
        }
        a = half.size()-(n-half.size());
        if(a < 0){
            a = a *(-1);
        }
        if(a < answer){
            answer = a;
        }
        
    }
    
    return answer;
}