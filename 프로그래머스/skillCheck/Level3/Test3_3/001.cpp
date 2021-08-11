#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int ans;
vector<vector<int>> isused;
vector<int> num;

void change(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            isused[i][j] = 0;
        }
    }
    for(int i=0;i<num.size();i++){
        // 좌우 
        for(int j=0;j<N;j++){
            isused[i][j] = 1;
        }
        // 세로
        for(int j=i;j<N;j++){
            isused[j][num[i]] = 1;
        }
        // 대각 
        for(int j=0;j<N-i;j++){
            if(i+j < N && num[i] + j < N){
                isused[i+j][num[i]+j] = 1;
            }
            if(i+j < N && num[i] - j >= 0){
                isused[i+j][num[i]-j] = 1;
            }
        }
        isused[i][num[i]] = 2;
    }
    return;
}

void func(int k){
    if(k == N){
        ans ++;
        for(int i=0;i<N;i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        cout << "\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout << isused[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return ;
    }

    for(int i=0;i<N;i++){
        if(!isused[k][i]){
            isused[k][i] = 1;
            num.push_back(i);
            change();
            func(k+1);
            isused[k][i] = 0;
            num.pop_back();
            change();
        }
    }
}



int solution(int n) {
    int answer = 0;
    N = n;
    ans = 0;
    isused.clear();
    num.clear();
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            tmp.push_back(0);
        }
        isused.push_back(tmp);
    }
    func(0);
    answer = ans;
    return answer;
}