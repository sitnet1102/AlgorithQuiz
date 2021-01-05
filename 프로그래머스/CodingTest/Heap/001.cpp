#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //bool check = true;
    sort(scoville.begin(), scoville.end());
    make_heap(scoville.begin(), scoville.end());
    while(true){
        
        int a, b, tmp;
        int num = scoville.size();
        ////
        for(int i=0;i<num;i++){
            cout << scoville[i] << " ";
        }
        cout << "\n";
        ////
        if(num==1 && scoville[0] < K){
            answer = -1;
            break;
        }
        
        a = scoville[0];
        b = scoville[1];
        scoville.erase(scoville.begin());
        scoville.erase(scoville.begin());
        tmp = a + b * 2;
        scoville.push_back(tmp);
        sort(scoville.begin(), scoville.end());
        answer++;
        if(scoville[0]>=K){
            break;
        }
    }
    return answer;
}