#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> front;
    vector<vector<int>> back;
    int num = 1;
    int layer = -1;
    for(int i=0;i<n;i++){
        vector<int> a;
        vector<int> b;
        front.push_back(a);
        back.push_back(b);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(i%3 == 0){
                layer ++;
                front[layer].push_back(num);
            }else if(i%3 == 1){
                front[layer].push_back(num);
            }else{
                layer --;
                back[layer].push_back(num);
            }
            num++;
        }
    }
    /*
    for(int i=0;i<front.size();i++){
        for(int j=0;j<front[i].size();j++){
            cout << front[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "==================\n";
    for(int i=0;i<back.size();i++){
        for(int j=0;j<back[i].size();j++){
            cout << back[i][j] << " ";
        }
        cout << "\n";
    }
    */
    

    for(int i=0;i<front.size();i++){
        for(int j=0;j<front[i].size();j++){
            answer.push_back(front[i][j]);
        }
        while(!back[i].empty()){
            answer.push_back(back[i].back());
            back[i].pop_back();
        }
    }
    return answer;
}