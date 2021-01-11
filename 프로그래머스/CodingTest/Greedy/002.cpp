#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    vector <int> v;
    int loca = 0;
    for(int i=0;i<name.size();i++){
        int tmp = (int)name[i] - 65;
        if(tmp > 13){
            tmp = 65 + 26 - (int)name[i];
        }
        //cout << tmp << " ";
        v.push_back(tmp);
    }
    while(true){
        int r, l;
        bool check = true;
        // answer 업데이트 
        answer = answer + v[loca];
        // 현재 위치 확인 후 
        // v 업데이트 
        v[loca] = 0;
        // 다음 위치 찾기 
        for(int i=0;i<v.size();i++){
            if(v[i] != 0){
                check = false;
                break;
            }
        }
        for(int i=1;i<v.size();i++){
            r = (loca + i) % name.size();
            l = (loca - i + name.size()) % name.size();
            if(v[r]){
                loca = r;
                answer = answer + i;
                break;
            }
            if(v[l]){
                loca = l;
                answer = answer + i;
                break;
            }
        }
        if(check){
            break;
        }
    }
    return answer;
}