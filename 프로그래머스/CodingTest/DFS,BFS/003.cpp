#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string Target = "";
vector<string> Words;
vector<int> isused;
int changeNum = 0;
int minNum = 51;

int difword(string a, string b){
    int dif = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i])
            dif ++;
    }
    return dif;
}

void func(string curStr){
    if(difword(curStr, Target) == 0){
        if(changeNum < minNum){
            minNum = changeNum;
        }
        return;
    }

    for(int i=0;i<isused.size();i++){
        if(!isused[i] && difword(curStr, Words[i]) == 1){
            isused[i] = 1;
            changeNum ++;
            func(Words[i]);
            isused[i] = 0;
            changeNum --;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    Target = target;
    changeNum = 0;
    minNum = 51;
    Words = words;
    isused.clear();
    for(int i=0;i<words.size();i++){
        isused.push_back(0);
    }
    func(begin);
    if(minNum != 51)
        answer = minNum;
    return answer;
}