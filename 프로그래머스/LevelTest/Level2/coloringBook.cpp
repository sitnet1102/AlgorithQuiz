#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> isused;
vector<vector<int>> p;
//vector<vector<int>> p1;
vector<int> ans;
vector<pair<int, int>> loca = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void func(){
    queue<pair<int, int>> q;
    //int alpha = 1;
    for(int i=1;i<p.size()-1;i++){
        for(int j=1;j<p[i].size()-1;j++){
            if(!isused[i][j]){
                pair<int, int> a;
                int num = 1;
                a.first = i;
                a.second = j;
                isused[i][j] = true;
                q.push(a);
                while(!q.empty()){
                    a = q.front();
                    //cout << a.first << " " << a.second << "\n";
                    q.pop();
                    for(int k=0;k<4;k++){
                        if(p[a.first][a.second] == p[a.first+loca[k].first][a.second+loca[k].second]){
                            if(!isused[a.first+loca[k].first][a.second+loca[k].second]){
                                pair<int, int> tmp;
                                tmp.first = a.first+loca[k].first;
                                tmp.second = a.second+loca[k].second;
                                isused[tmp.first][tmp.second] = true;
                                num++;
                                q.push(tmp);
                                //p1[tmp.first][tmp.second] = alpha;
                            }
                        }
                    }
                }
                //cout << "\n";
                ans.push_back(num);
                //alpha++;
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    vector<int> a;
    vector<bool> b;
    isused.clear();
    p.clear();
    ans.clear();
    for(int i=0;i<n+2;i++){
        a.push_back(0);
        b.push_back(1);
    }
    p.push_back(a);
    for(int i=0;i<picture.size();i++){
        vector<int> tmp;
        tmp = picture[i];
        tmp.insert(tmp.begin(),0);
        tmp.push_back(0);
        p.push_back(tmp);
    }
    p.push_back(a);
    ////
    p1 = p;
    ///
    isused.push_back(b);
    for(int i=0;i<m;i++){
        vector<bool> tmp;
        tmp.push_back(1);
        for(int j=0;j<n;j++){
            if(picture[i][j] == 0){
                tmp.push_back(1);
            }else{
                tmp.push_back(0);
            }
        }
        tmp.push_back(1);
        isused.push_back(tmp);
    }
    isused.push_back(b);


    /*
    for(int i=0;i<p.size();i++){
        for(int j=0;j<p[i].size();j++){
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for(int i=0;i<p1.size();i++){
        for(int j=0;j<p1[i].size();j++){
            cout << p1[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for(int i=0;i<isused.size();i++){
        for(int j=0;j<isused[i].size();j++){
            cout << isused[i][j] << " ";
        }
        cout << "\n";
    }
    */
    func();
    sort(ans.begin(),ans.end());
    /*
    cout << "\n";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    */
    answer[0] = ans.size();
    if(ans.empty()){
        ans.push_back(0);
    }
    answer[1] = ans.back();
    return answer;
}