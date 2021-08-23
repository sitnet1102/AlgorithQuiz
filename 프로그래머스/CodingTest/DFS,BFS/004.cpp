#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> isused;
vector<vector<string>> Tickets;
vector<string> retStr;
vector<vector<string>> ans;
string cur;


void func(int k){
    if(k == isused.size()){
        ans.push_back(retStr);
        return;
    }
    
    for(int i=0;i<isused.size();i++){
        if(!isused[i] && Tickets[i][0].compare(cur) == 0){
            isused[i] = 1;
            cur = Tickets[i][1];
            retStr.push_back(cur);
            func(k+1);
            isused[i] = 0;
            cur = Tickets[i][0];
            retStr.pop_back();
        }
    }
    
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    isused.clear();
    Tickets.clear();
    retStr.clear();
    ans.clear();
    cur = "ICN";
    retStr.push_back(cur);
    
    for(int i=0;i<tickets.size();i++){
        isused.push_back(0);
    }
    Tickets = tickets;
    func(0);
    sort(ans.begin(),ans.end());
    /*
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    */
    answer = ans[0];
    return answer;
}