#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int solution(int n) {
    int arr[60001] = {0, 1, 2, 0,};
    int answer = 0;
    for(int i=3;i<=n;i++){
        long long int tmp = arr[i-1] + arr[i-2];
        if(tmp >=1000000007){
            tmp = tmp % 1000000007;
        }
        arr[i] = tmp;
    }
    answer = arr[n];
    return answer;
}