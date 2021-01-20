#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    double a = sqrt(n);
    long long b = floor(a);
    if(a <= b){
        answer = (b+1) * (b+1);
    }
    return answer;
}