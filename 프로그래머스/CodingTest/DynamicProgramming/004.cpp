#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> money) {
    int answer = 0;
    vector<int> v;
    vector<bool> w;
    if(money.size() == 3){
        sort(money.begin(), money.end(), cmp);
        answer = money[0];
        return answer;
    }
    for(int i=0;i<2;i++){
        v.push_back(money[i]);
    }
    w.push_back(1);
    w.push_back(0);
    w.push_back(1);
    v.push_back(money[2] + money[0]);
    for(int i=3;i<money.size();i++){
        int max = v[i-3] + money[i];
        bool f = w[i-3];
        if(v[i-3] < v[i-2]){
            max = money[i] + v[i-2];
            f = w[i-2];
        }
        v.push_back(max);
    }
    if(w.back() == 1){
        answer = v[v.size()-2];
    }else{
        if(v[v.size()-1] > v[v.size()-1]){
            answer = v[v.size()-1];
        }else{
            answer = v[v.size()-2];
        }
    }
    return answer;
}

// 11 0 13 16 113 116 198 117