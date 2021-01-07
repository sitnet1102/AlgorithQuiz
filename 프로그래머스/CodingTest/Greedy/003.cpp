#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    bool check = true;
    // 순서대로 돌면서 앞부터 증가하면 앞에것 지우기
    /* 
    for(int j=0;j<number.size()-1;j++){
        int a, b;
        a = stoi(number.substr(j,1));
        b = stoi(number.substr(j+1,1));
        if(a!=b){
            check = false;
            break;
        }
    }
    */
    if(check){
        answer = number.substr(0, number.size()-k);
        return answer;
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<number.size()-1;j++){
            int a, b;
            a = stoi(number.substr(j,1));
            b = stoi(number.substr(j+1,1));
            if(a < b){
                string A, B;
                A = number.substr(0, j);
                B = number.substr(j+1, number.size());
                number = A + B;
                //cout << "number : " << number << "\n";
                break;
            }
            if(j == number.size()-2){
                number = number.substr(0, number.size()-1);
            }

            //cout << "--------------\n";
            //cout << a << " " << b << "\n";
        }
    }

    answer = number;


    return answer;
}