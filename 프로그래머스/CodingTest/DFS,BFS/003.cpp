#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int checker(string a, string b){
    int num = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i]){
            num ++;
        }
    }
    return num;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    sort(words.begin(),words.end());
    for(int i=0;i<words.size();i++){
        cout << words[i] << " "; 
    }
    cout <<"\n";
    while(begin != target){
    }
    return answer;
}