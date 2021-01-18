#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int a;
    for(int i=0;i<seoul.size();i++){
        if(seoul[i] == "Kim"){
            a = i;
        }
    }
    answer = answer + to_string(a);
    answer = answer + "에 있다";
    return answer;
}