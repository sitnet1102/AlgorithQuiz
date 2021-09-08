#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> W;
vector<vector<int>> order;

bool cmp(vector<int> a, vector<int> b){
    float A = 0;
    float B = 0;
    if(a[2] != 0){
        A = (float)a[3] / (float)a[2];
    }
    if(b[2] != 0){
        B = (float)b[3] / (float)b[2];
    }
    if(A == B){
        if(a[1] == b[1]){
            if(W[a[0]] == W[b[0]]){
                return a[0] < b[0];
            }
            return W[a[0]] > W[b[0]];
        }
        return a[1] > b[1];
    }
    return A > B;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    W = weights;
    for(int i=0;i<head2head.size();i++){
        int win = 0;
        int game = 0;
        int wintotal = 0;
        vector<int> tmp;
        for(int j=0;j<head2head[i].size();j++){
            if(head2head[i][j] == 'W' && weights[i] < weights[j]){
                win ++;
            }
            if(head2head[i][j] != 'N'){
                game ++;
            }
            if(head2head[i][j] == 'W'){
                wintotal ++;
            }
        }
        tmp.push_back(i);
        tmp.push_back(win);
        tmp.push_back(game);
        tmp.push_back(wintotal);
        order.push_back(tmp);
    }
    sort(order.begin(),order.end(),cmp);
    for(int i=0;i<order.size();i++){
        //cout << order[i][0] << " " << order[i][1] << " " << order[i][2] << " " << order[i][3] << "\n";
        answer.push_back(order[i][0] + 1);
    }
    return answer;
}