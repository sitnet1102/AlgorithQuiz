#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int num = phone_number.size();
    answer = phone_number;
    for(int i=0;i<num-4;i++){
        answer[i] = '*';
    }
    return answer;
}

int main(){
    string p_num;
    cin >> p_num;
    cout << solution(p_num);
}