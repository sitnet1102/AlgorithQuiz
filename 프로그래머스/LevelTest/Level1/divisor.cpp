#include <string>
#include <vector>
#include <math.h>

using namespace std;
/*
int solution(int n) {
    int answer = 0;
    vector <int> v = {2,};
    vector <int> a = {0,};
    for(int i=2;i<sqrt(n);i++){
        bool check = true;
        for(int j=0;j<v.size();j++){
            if(i % v[j] == 0){
                check = false;
                break;
            }
        }
        if(check){
            v.push_back(i);
            a.push_back(0);
        }
    }
    while(n == 1){
        for(int i=0;i<v.size();i++){
            if(n % v[i] == 0){
                a[i]++;
                n = n/v[i];
                break;
            }
        }
    }
    return answer;
}
*/
int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(n % i == 0){
            answer = answer + i;
        }
    }
    return answer;
}