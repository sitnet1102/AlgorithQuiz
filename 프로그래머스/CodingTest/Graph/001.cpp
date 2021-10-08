#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> v;
    vector<int> cost;
    vector<int> isused;
    queue<int> q;
    int max = -1;
    for(int i=0;i<=n;i++){
        vector<int> tmp;
        v.push_back(tmp);
        cost.push_back(n);
        isused.push_back(0);
    }
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    /*
    for(int i=0;i<v.size();i++){
        cout << i << "  ---  ";
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    q.push(1);
    isused[1] = 1;
    cost[1] = 0;
    
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int i=0;i<v[num].size();i++){
            if(!isused[v[num][i]]){
                if(cost[v[num][i]] > cost[num] + 1){
                    cost[v[num][i]] = cost[num] + 1;
                }
                q.push(v[num][i]);
                isused[v[num][i]] = 1;
            }
        }
    }
    
    /*
    cout << "cost  ---  ";
    for(int i=0;i<cost.size();i++){
        cout << cost[i] << " ";
    }
    */
    
    for(int i=1;i<cost.size();i++){
        if(max < cost[i]){
            max = cost[i];
            answer = 1;
        }else if(max == cost[i]){
            answer ++;
        }
    }
    
    
    return answer;
}