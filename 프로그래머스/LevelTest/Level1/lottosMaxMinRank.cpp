#include <bits/stdc++.h>

using namespace std;

int rank_sol(int num){
    if(num == 6){
        return 1;
    }else if(num == 5){
        return 2;
    }else if(num == 4){
        return 3;
    }else if(num == 3){
        return 4;
    }else if(num == 2){
        return 5;
    }else{
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeronum = 0;
    int c = 0;
    int min = 0;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    /*
    for(int e : lottos)
        cout << e << " ";
    cout << "\n";
    for(int e : win_nums)
        cout << e << " ";
    */
    for(int i=0;i<lottos.size();i++){
        if(lottos[i] == 0){
            zeronum++;
        }else{
            while(lottos[i] > win_nums[c] && c < 6){
                c++;
            }
            if(lottos[i] == win_nums[c]){
                min ++;
            }
        }
    }
    answer.push_back(rank_sol(min+zeronum));
    answer.push_back(rank_sol(min));
    
    return answer;
}