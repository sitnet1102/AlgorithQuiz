#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> p = {2};
    for(int i=2;i<=n;i++){
        bool check = true;
        for(int j=0;j<p.size();j++){
            if(i%p[j] == 0){
                check = false;
                break;
            }
            if(p[j] > sqrt(i)){
                break;
            }
        }
        if(check){
            p.push_back(i);
        }
    }
    answer = p.size();
    return answer;
}