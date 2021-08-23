#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min;
    long long max;
    long long min_time = 1000000000;
    for(int t : times){
        if(t < min_time){
            min_time = t;
        }
    }
    min = min_time;
    max = min_time * n;
    //cout << min << " " << max << " " << min_time;
    while(min <= max){
        long long mid = (max + min) / (long long)2;
        int count = 0;
        for(int i=0;i<times.size();i++){
            count = count + mid / (long long)times[i];
            if(count >= n){
                max = mid-1;
                break;
            }
        }
        if(count < n){
            min = mid+1;
        }
        answer = min;
        //cout << min << " " << max << " " << min_time << "\n";
    }
    return answer;
}


/*
https://changyeon2.tistory.com/20
*/