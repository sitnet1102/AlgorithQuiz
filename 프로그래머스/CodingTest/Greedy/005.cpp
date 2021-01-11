#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector <int>> v;
    vector<vector <int>> w;
    for(int i=0;i<n;i++){
        vector <int> tmp;
        vector <int> tmp2;
        v.push_back(tmp);
        for(int j=0;j<n;j++){
            tmp2.push_back(0);
        }
        w.push_back(tmp2);
    }

    for(int i=0;i<costs.size();i++){
        v[costs[i][0]].push_back(costs[i][1]); 
        v[costs[i][1]].push_back(costs[i][0]);
        w[costs[i][0]][costs[i][1]] = costs[i][2];
        w[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    /*
    cout << "v =====================\n";
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "w =========================\n";
    for(int i=0;i<w.size();i++){
        for(int j=0;j<w[i].size();j++){
            cout << w[i][j] << " ";
        }
        cout << "\n";
    }
    */

    

    
    return answer;
}