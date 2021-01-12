#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a[2] == b[2]){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector <int> v;
    if(n==1){
        return 0;
    }
    sort(costs.begin(), costs.end(), comp);
    for(int i=0;i<n;i++){
        v.push_back(i);
    }
    /*
    for(int i=0;i<costs.size();i++){
        cout << costs[i][0] << " " << costs[i][1] << " " << costs[i][2] << "\n";
    }
    */
    for(int i=0;i<costs.size();i++){
        bool check = true;
        // costs[i][0], costs[i][1], costs[i][2]
        //     노드         노드        비용
        // 사이클이 되는지 확인 -> v 에서 0번 1번이 같은 부모 노드를 가르키고 있는지 확인 
        if(v[costs[i][0]] == v[costs[i][1]]){
            continue;
        }else{
        // 사이클이 안된다면 업데이트           answer 비용 업데이트, v 부모노드 업데이트 
            int before;
            answer = answer + costs[i][2];
            before = v[costs[i][1]];
            v[costs[i][1]] = v[costs[i][0]];
            for(int j=0;j<v.size();j++){
                if(v[j] == before){
                    v[j] = v[costs[i][1]];
                }
            }
        }
        
        // v가 모두 같은 노드를 가르키는지 확인 -> 전부 들어가 있음을 뜻함 
        for(int j=1;j<v.size();j++){
            if(v[j] != v[j-1]){
                check = false;
            }
        }
        // 전부 들어가 있으면 종료 break 
        if(check){
            break;
        }
    }

    return answer;
}

/*
    5
    [
        [0, 2, 1],
        [0, 1, 1],
        [2, 3, 5],
        [4, 2, 1]

    ]

    n=6
costs = [[0, 1, 5], [0, 3, 2], [0, 4, 3], [1, 4, 1], [3, 4, 10], [1, 2, 2], [2, 5, 3], [4, 5, 4]]
답 11

*/