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
        
    }
    
    return answer;
}