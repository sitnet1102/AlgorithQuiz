#include <string>
#include <vector>

using namespace std;

vector<int> isused;
vector<int> num;
int n;
int t;
int ans = 0;

void func(int k){

    if(k==n){
        int sum = 0;
        for(int i=0;i<isused.size();i++){
            if(isused[i] == 1){
                sum = sum + num[i];
            }else if(isused[i] == 0){
                sum = sum - num[i];
            }
        }
        if(sum == t){
            ans ++;
        }
        return ;
    }

    for(int i=0;i<n;i++){
        if(!isused[i]){
            isused[i] = 1;  // 더하기 
            func(k+1);
        }
    }

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    isused.clear();
    for(int i=0;numbers.size();i++){
        isused.push_back(0);
    }
    num.clear();
    for(int i=0;i<numbers.size();i++){
        num.push_back(numbers[i]);
    }
    n = numbers.size();
    t = target;
    func(0);
    return answer;
}