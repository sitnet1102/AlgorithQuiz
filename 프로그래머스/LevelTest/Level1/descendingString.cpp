#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char a, char b){
    return a > b;
}

string solution(string s) {
    string answer = "";
    vector<char> str;
    for(int i=0;i<s.size();i++){
        str.push_back(s[i]);
    }
    sort(str.begin(), str.end(), cmp);
    for(int i=0;i<str.size();i++){
        answer = answer + str[i];
    }
    return answer;
}