#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> q;
    for(int i=0;i<operations.size();i++){
        char opt = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if(opt == 'I'){
            q.push_back(num);
            sort(q.begin(),q.end(),comp);
        }else if(opt == 'D'){
            if(!q.empty()){
                if(num == 1){
                    q.erase(q.begin());
                }else if(num == -1){
                    q.pop_back();
                }
            }
        }
    }
    /*
    for(int i=0;i<q.size();i++){
        cout << q[i] << " ";
    }
    cout << "\n";
    */
    
    if(q.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(q[0]);
        answer.push_back(q.back());
    }

    return answer;
}

/*
#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    char opt = operations[0][0];
    int num = stoi(operations[0].substr(2));
    if(num < 0){
        cout << "hi\n";
    }
    cout << opt << " " << num;
    return answer;
}
*/