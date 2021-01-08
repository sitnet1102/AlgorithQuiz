#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = -1;
    int n = number.size() - k;
    vector<int> v;
    for(int i=0;i<number.size()-k;i++){
        int max = -1;
        int num = -1;
        for(int j=index+1;j<k+1+i;j++){
            //cout << number[j] << " ";
            if(number[j] > max){
                max = number[j];
                num = j;
                if(number[j] == '9'){
                    break;
                }
            }
        }
        v.push_back(num);
        index = num;
        //cout << "\n";
    }
    for(int i=0;i<v.size();i++){
        answer = answer + number[v[i]];
    }

    return answer;
}