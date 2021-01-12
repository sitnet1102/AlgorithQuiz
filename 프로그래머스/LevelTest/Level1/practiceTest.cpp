#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ans1[5] = {1,2,3,4,5};
    int ans2[8] = {2,1,2,3,2,4,2,5};
    int ans3[10] = {3,3,1,1,2,2,4,4,5,5};
    int num[4] = {0,0,0,0};
    int max = -1;
    for(int i=0;i<answers.size();i++){
        int a, b, c;
        a = i % 5;
        b = i % 8;
        c = i % 10;
        if(answers[i] == ans1[a]){
            num[1] = num[1] + 1;
        }
        if(answers[i] == ans2[b]){
            num[2] = num[2] + 1;
        }
        if(answers[i] == ans3[c]){
            num[3] = num[3] + 1;
        }
        //cout << a << " " << b << " " << c << "\n";
    }
    for(int i=1;i<4;i++){
        if(max < num[i]){
            max = num[i];
        }
        //cout << num[i] << " ";
    }
    for(int i=1;i<4;i++){
        if(max == num[i]){
            answer.push_back(i);
        }
    }
    return answer;
}