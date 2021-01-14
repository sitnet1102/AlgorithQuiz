#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int num = s.size();
    if(num%2 == 0){
        answer = s.at(num/2-1);
        answer = answer + s.at(num/2);
    }else{
        answer = s.at(num/2);
    }
    return answer;
}