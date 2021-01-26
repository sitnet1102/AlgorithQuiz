/// 그래프 문제 
// 

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> win;
    vector<vector<int>> lose;
    vector<int> v(n);

    for(int i=0;i<=n;i++){
        vector<int> tmp;
        win.push_back(tmp);
        lose.push_back(tmp);
    }

    for(int i=0;i<results.size();i++){
        win[results[i][0]].push_back(results[i][1]);
        lose[results[i][1]].push_back(results[i][0]);
    }

    cout << "win ============================\n";
    for(int i=0;i<win.size();i++){
        cout << i << " : ";
        for(int j=0;j<win[i].size();j++){
            cout << win[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "lose ============================\n";
    for(int i=0;i<lose.size();i++){
        cout << i << " : ";
        for(int j=0;j<lose[i].size();j++){
            cout << lose[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "iii ============================\n";
    for(int i=0;i<=n;i++){
        if(win[i].size() + lose[i].size() == n-1){
            cout << "ii == " << i << "\n";
        }
    }

    return answer;
}