#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(true){
        
        int a, b, tmp;
        int num = pq.size();
        if(num==1 && pq.top() < K){
            answer = -1;
            break;
        }
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        tmp = a + b * 2;
        pq.push(tmp);
        answer++;
        if(pq.top()>=K){
            break;
        }
    }
    return answer;
}