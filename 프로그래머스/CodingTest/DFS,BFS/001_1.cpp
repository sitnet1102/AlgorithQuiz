#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int isused[20];
int num[20];
int n;
int t;
int ans = 0;

void func(int k, int a, int loca){
    if(k==a){
        int sum = 0;
        for(int i=0;i<n;i++){
            if(isused[i] == 1){
                sum = sum + num[i];
            }else{
                sum = sum - num[i];
            }
        }
        /*
        for(int i=0;i<n;i++){
            cout << isused[i] << " ";
        }
        cout <<"\n";
        */
        if(sum == t){
            //cout <<"\n";
            ans ++;
        }
        return ;
    }
    for(int i=loca;i<n;i++){
        if(!isused[i]){
            isused[i] = 1;
            func(k+1,a,i);
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
        func(0,i,0);
    }
    answer = ans;
    return answer;
}