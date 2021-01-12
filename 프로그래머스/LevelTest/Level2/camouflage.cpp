#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<string> a, vector<string> b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int num=0;
    int r_num=1;
    vector<int> v;
    sort(clothes.begin(), clothes.end(), comp);
    cout << clothes.size() << "\n";
    if(clothes.size() == 1){
        return 1;
    }

    for(int i=0;i<clothes.size();i++){
        num++;
        if(i==clothes.size()-1){
            v.push_back(num);
        }else{
            if(clothes[i][1] != clothes[i+1][1]){
                v.push_back(num);
                num = 0;
            }
        }
    }
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
        r_num = r_num * (v[i]+1);
    }
    cout << "\n";
    
    for(int i=0;i<clothes.size();i++){
        cout << clothes[i][0] << " " << clothes[i][1] << "\n";
    }
    
    
    answer = r_num - 1;
    return answer ;
}