#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int tmp;
    int index;
    sort(arr.begin(), arr.end());
    tmp = arr[0];
    for(int i=0;i<answer.size();i++){
        if(tmp == answer[i]){
            index = i;
            break;
        }
    }
    answer.erase(answer.begin() + index);
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    return answer;
}