#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int score[4] = {0,0,0,0};
    int max_num = 0;
    for(int i=0;i<land.size();i++){
        int tmp[4] = {0,0,0,0};
        for(int j=0;j<4;j++){               // j -> 이번 행에서 선택할 땅 번호 
            int max = 0;
            for(int k=0;k<4;k++){           // k -> 이전 행에서 선택할 땅 번호 -> 가장 큰 번호 선택 
                if(j!=k){
                    if(max < score[k]){
                        max = score[k];
                    }
                }
            }
            tmp[j] = land[i][j] + max;
        }
        for(int j=0;j<4;j++){
            score[j] = tmp[j];
        }
    }
    for(int i=0;i<4;i++){
        if(max_num < score[i]){
            max_num = score[i];
        }
    }
    answer = max_num;

    return answer;
}