#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int isused[20];
int num[20];
int n;
int t;
int s;
int ans = 0;

void func(int k, int a){
    if(k==a){
        int sum = s;
        for(int i=0;i<n;i++){
            if(isused[i] == 1){
                sum = sum - num[i];
            }
        }
        if(sum == t){
            ans ++;
        }
        return ;
    }
    for(int i=0;i<n;i++){
        if(!isused[i]){
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    for(int i=0;i<numbers.size();i++){
        num[i] = numbers[i];
    }
    n = numbers.size();
    t = target;
    for(int i=1;i<n;i++){
        func(0,i);
    }
    answer = ans;
    return answer;
}