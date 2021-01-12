#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), comp);
    for(int i=0;i<citations.size();i++){
        //cout << citations[i] << " ";
    }
    cout << "\n";
    for(int h=0;h<citations.size();h++){
        if(citations[h] < h+1){
            break;
        }else{
            answer = h+1;
        }
    }
    return answer;
}