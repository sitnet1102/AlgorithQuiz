#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<string> s;
    for(int i=0;i<skill.size();i++){
        s.push_back(skill.substr(i,1));
    }
    for(int i=0;i<skill_trees.size();i++){
        int num = 0;
        int num2 = 0;
        vector<int> v;
        for(int j=0;j<s.size();j++){
            v.push_back(0);
        }
        for(int j=0;j<skill_trees[i].size();j++){
            for(int k=0;k<s.size();k++){
                if(skill_trees[i].substr(j,1) == s[k]){
                    v[k] = 1;
                }
            }
            if(s[num] == skill_trees[i].substr(j,1)){
                num ++;
            }
        }
        for(int j=0;j<v.size();j++){
            if(v[j]==1){
                num2++;
            }
        }
        if(num == num2){
            answer++;
            //cout << skill_trees[i] << "\n";
        }
    }
    return answer;
}