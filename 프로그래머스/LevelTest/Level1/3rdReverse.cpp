#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 1;
    string num = "";
    while(n){
        int tmp;
        tmp = n % 3;
        n = n/3;
        num = to_string(tmp) + num;
    }
    //cout << num << "\n";
    for(int i=0;i<num.size();i++){
        int tmp = (int)num[i] - 48;
        answer = answer + tmp * a;
        a = a * 3;
        //cout << tmp << " ";
    }
    return answer;
}