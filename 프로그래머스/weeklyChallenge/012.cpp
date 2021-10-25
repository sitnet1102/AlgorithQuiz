#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int K;
int ans;
vector<int> isused;
vector<int> v;
vector<vector<int>> d;

void func(int a){
    if(a == N){
        int kNum = K;
        int num = 0;
        for(int i=0;i<v.size();i++){
            if(kNum >= d[v[i]][0] && kNum >= 0){
                kNum = kNum - d[v[i]][1];
                num ++;
            }
        }
        if(ans < num){
            ans = num;
        }
        return;
    }
    
    for(int i=0;i<N;i++){
        if(!isused[i]){
            v.push_back(i);
            isused[i] = 1;
            func(a+1);
            v.pop_back();
            isused[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    N = dungeons.size();
    K = k;
    ans = 0;
    isused.clear();
    for(int i=0;i<dungeons.size();i++){
        isused.push_back(0);
    }
    v.clear();
    d.clear();
    d = dungeons;
    func(0);
    
    answer = ans;
    
    return answer;
}