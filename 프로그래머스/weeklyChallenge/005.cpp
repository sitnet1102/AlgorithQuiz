#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<char> alpha = {'A', 'E', 'I', 'O', 'U'};

bool cmp(string a, string b){
    return a < b;
}

int solution(string word) {
    int answer = 0;
    vector<string> words;
    for(int i=0;i<alpha.size();i++){
        string tmp = "";
        tmp.push_back(alpha[i]);
        words.push_back(tmp);
        for(int j=0;j<alpha.size();j++){
            tmp.push_back(alpha[j]);
            words.push_back(tmp);
            for(int k=0;k<alpha.size();k++){
                tmp.push_back(alpha[k]);
                words.push_back(tmp);
                for(int l=0;l<alpha.size();l++){
                    tmp.push_back(alpha[l]);
                    words.push_back(tmp);
                    for(int m=0;m<alpha.size();m++){
                        tmp.push_back(alpha[m]);
                        words.push_back(tmp);
                        tmp.pop_back();
                    }
                    tmp.pop_back();
                }
                tmp.pop_back();
            }
            tmp.pop_back();
        }
    }
    sort(words.begin(), words.end(),cmp);
    for(int i=0;i<words.size();i++){
        //cout << words[i] << "\n";
        if(word == words[i]){
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}