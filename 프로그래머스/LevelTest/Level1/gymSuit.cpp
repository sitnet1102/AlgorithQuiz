#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    /*
    for(int i=0;i<lost.size();i++){
        cout << lost[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<reserve.size();i++){
        cout << reserve[i] << " ";
    }
    cout << "\n";
    */
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i] == reserve[j]){
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                answer ++;
            }
        }
    }
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            //cout << "=======================================\n";
            //cout << "lost : " << lost[i] << " reserve : " << reserve[j] << "\n";

            if(lost[i] == reserve[j]+1 || lost[i] == reserve[j]-1){
                reserve.erase(reserve.begin() + j);
                answer ++;
                //cout << answer << "\n";
                break;
            }
        }
    }
    return answer;
}

//5, [1,2,4,5] [2,3,4] -> 3
//3, [1,2], [2,3] -> 2
//Lost = {10,16,19,20,24,26,27};
//Reserve = {4,7,8,10,13,14,16,17,18,19,21,22,23,24,25,26,27};