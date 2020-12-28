#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int a;
    answer = "김서방은 ";
    for(int i=0;i<seoul.size();i++){
        if(seoul[i] == "Kim"){
            a = i;
        }
    }
    answer = answer + to_string(a) + "에 있다";

    return answer;
}

int main(){
    int n;
    vector<string> seoul;

    cin >> n;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        seoul.push_back(tmp);
    }
    cout << solution(seoul);



    return 0;
}