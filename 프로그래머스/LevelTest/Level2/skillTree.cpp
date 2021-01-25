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
        for(int j=0;j<skill_trees[i].size();j++){
            if(s[num] == skill_trees[i].substr(j,1)){
                num ++;
            }
        }
        if(num == skill.size()){
            answer++;
            cout << skill_trees[i] << "\n";
        }
    }
    return answer;
}