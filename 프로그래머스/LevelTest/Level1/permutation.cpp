#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int tmp = 0;
    for(int i=0;i<n;i++){
        tmp = tmp + x;
        answer.push_back(tmp);
    }
    return answer;
}