#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<vector<int>> v;
    vector<int> zero;
    zero.push_back(0);
    v.push_back(zero);
    for(int i=1;i<=8;i++){
        vector<int> tmp;
        // i개 만큼 연속되는 숫자 가 32000 보다 큰지 확인 안된다면 넣어주기 
        if(i<=5){
            string s = "";
            for(int j=0;j<i;j++){
                s = s + to_string(N);
            }
            if(stoi(s) <= 32000){
                tmp.push_back(stoi(s));
            }
        }
        for(int j=1;j<i;j++){
            for(int x=0;x < v[j].size();x++){
                for(int y=0;y < v[i-j].size();y++){
                    //cout << "i : " << i << " | j : " << j << " | x : " << x << " | y : " << y << "\n";
                    tmp.push_back(v[j][x] + v[i-j][y]);
                    if(v[j][x] > v[i-j][y]){
                        tmp.push_back(v[j][x] - v[i-j][y]);
                    }
                    if(v[i-j][y] != 0){
                        tmp.push_back((int)(v[j][x] / v[i-j][y]));
                    }
                    tmp.push_back(v[j][x] * v[i-j][y]);
                }
            }
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()),tmp.end());
        if(tmp[0] == 0){
            tmp.erase(tmp.begin());
        }
        for(int j=0;j<tmp.size();j++){
            cout << tmp[j] << " ";
        }
        cout << "\n";
        for(int j=0;j<tmp.size();j++){
            if(tmp[j] == number){
                return i;
            }
        }
        v.push_back(tmp);
    }
    return answer;
}

int main(){

    cout << solution(5, 12) << "\n";
    cout << solution(2, 11) << "\n";
    //cout << solution(5, 31168) << "\n";
    

    return 0;
}