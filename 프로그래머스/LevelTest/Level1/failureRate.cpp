#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> v;
    sort(stages.begin(), stages.end());
    for(int i=1;i<=N;i++){
        pair<int, double> p;
        int notuser = 0;
        int fail_person = 0;
        p.first = i;
        for(int j=0;j<stages.size();j++){
            if(stages[j] == i){
                fail_person++;
            }else if(stages[j] > i){
                break;
            }else{
                notuser ++;
            }
        }
        if(notuser == stages.size()){
            p.second = 0;
        }else{
            p.second = (float)fail_person / (float)(stages.size() - notuser);
        }
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<v.size();i++){
        //cout << v[i].first << " " << v[i].second <<"\n"; 
        answer.push_back(v[i].first);
    }
    return answer;
}