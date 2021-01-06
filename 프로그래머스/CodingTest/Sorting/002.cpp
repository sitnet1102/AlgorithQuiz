#include <string>
#include <vector>

using namespace std;

vector<int> num;
vector<bool> isused;
vector<string> v;
int n;
string max_num = "";

void func(int k){

    if(k == n){
        string tmp;
        for(int i=0;i<n;i++){
            tmp = tmp + v[i];
        }

        if(max_num == ""){
            max_num = tmp;
        }else if(tmp > max_num){
            max_num = tmp;
        }
        return ;
    }

    for(int i=0;i<n;i++){
        if(!isused[i]){
            isused[i] = true;
            v.push_back(to_string(num[i]));
            func(k+1);
            isused[i] = false;
            v.pop_back();
        }
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    n = numbers.size();
    for(int i=0;i<n;i++){
        num.push_back(numbers[i]);
        isused.push_back(false);
    }
    func(0);
    answer = max_num;
    
    return answer;
}