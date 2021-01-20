#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    while(n){
        int tmp = n%10;
        n = n/10;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<v.size();i++){
        answer = answer*10 + v[i];
    }
    return answer;
}