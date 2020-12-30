#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n;i++){
        cout << "========================== i = " << i << "\n";
        int sum = 0;
        int k = i;
        while(sum < n){
            sum = sum + k;
            k++;
        }
        cout << "sum = " << sum << "\n";
        if(sum == n){
            answer++;
        }
    }
    return answer;
}