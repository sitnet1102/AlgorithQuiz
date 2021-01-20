#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for(int i=0;i<s.size();i++){
        char tmp = s[i];
        if(tmp != 32){
            if(index % 2 == 0){
                if(s[i] >= 97){
                    s[i] = s[i] - 32;
                }
            }else{
                if(s[i] <= 90){
                    s[i] = s[i] + 32;
                }
            }
            index ++;
        }else{
            index = 0;
        }

    }
    answer = s;
    return answer;
}