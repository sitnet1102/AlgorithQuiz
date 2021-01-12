#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(int a, int b){
    return a < b;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int a=0;a<commands.size();a++){
        int i = commands[a][0];
        int j = commands[a][1];
        int k = commands[a][2];
        vector<int> v;
        for(int b=i-1;b<j;b++){
            v.push_back(array[b]);
            
        }
        /*
        cout << "========================================\n";
        for(int x=0;x<v.size();x++){
            cout << v[x] << " ";
        }
        cout << "\n";
        */
        sort(v.begin(), v.end(), comp);
        answer.push_back(v[k-1]);
        /*
        for(int x=0;x<v.size();x++){
            cout << v[x] << " ";
        }
        cout << "\n";
        */
    }
    return answer;
}