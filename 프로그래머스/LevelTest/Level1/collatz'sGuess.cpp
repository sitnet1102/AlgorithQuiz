#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    long long n = num;
    int answer = 0;
    while(n != 1){
        //cout << n << "\n";
        if(n%2 == 0){
            n = n/2;
        }else{
            n = n * 3 + 1;
        }
        answer ++;
        if(answer > 500){
            return -1;
        }
    }

    return answer;
}