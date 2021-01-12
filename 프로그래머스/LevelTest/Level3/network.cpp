#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> v;
    vector<vector <int> > node;
    for(int i=0;i<n;i++){
        v.push_back(i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i <= j){
                break;
            }
            if(computers[i][j] == 1){
                vector<int> tmp;
                tmp.push_back(j);
                tmp.push_back(i);
                node.push_back(tmp);
            }
        }
    }
    /*
    
    for(int i=0;i<node.size();i++){
        cout << node[i][0] << " " << node[i][1] << "\n";
    }
    */
    for(int i=0;i<node.size();i++){
        int tmp = v[node[i][1]];
        if(v[node[i][0]] == v[node[i][1]]){
            continue;
        }else{
            v[node[i][1]] = v[node[i][0]];
            for(int j=0;j<n;j++){
                if(v[j] == tmp){
                    v[j] = v[node[i][0]];
                }
            }
        }
    }
    /*
    
    for(int i=0;i<v.size();i++){
        cout << v[i];
    }
    cout << "\n";
    */
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    answer = v.size();
    /*
    
    for(int i=0;i<v.size();i++){
        cout << v[i];
    }
    cout << "\n";
    */
    return answer;
}