#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> isused;
vector<vector<int>> p;
vector<vector<int>> ans;
int num = 0;

void func(int x, int y){

    if(p[x][y+1] != 0 && p[x][y-1] != 0 && p[x+1][y] != 0 && p[x-1][y] != 0){
        return;
    }

    for(int i=1;i<p.size()-1;i++){
        for(int j=1;j<p[i].size()-1;j++){
            // up
            if(p[i][j] == p[i-1][j] && !isused[i-1][j]){
                
            }
            // right
            if(p[i][j] == p[i][j+1] && !isused[i][j+1]){

            }
            // left
            if(p[i][j] == p[i][j-1] && !isused[i][j-1]){

            }
            // down
            if(p[i][j] == p[i+1][j] && !isused[i+1][j]){
            
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    vector<int> a;
    vector<int> b;
    isused.clear();
    p.clear();
    for(int i=0;i<n+2;i++){
        a.push_back(0);
        b.push_back(-1);
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
    isused.push_back(b);
    for(int i=0;i<m;i++){
        vector<int> tmp;
        tmp.push_back(-1);
        for(int j=0;j<n;j++){
            if(picture[i][j] == 0){
                tmp.push_back(-1);
            }else{
                tmp.push_back(0);
            }
        }
        tmp.push_back(-1);
        isused.push_back(tmp);
    }
    isused.push_back(b);



    for(int i=0;i<p.size();i++){
        for(int j=0;j<p[i].size();j++){
            cout << p[i][j] << " ";
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
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}