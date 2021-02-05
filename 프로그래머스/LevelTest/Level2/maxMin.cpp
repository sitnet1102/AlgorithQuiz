#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<long> v;
    for(int i=0;i<s.size();i++){
        string tmp = s.substr(i,1);
        string num_str = "";
        long num;

        /*
        if(tmp == "-"){
            i++;
            tmp = tmp + s.substr(i,1);
        }else if(tmp == " "){
            continue;
        }
        */

        while( tmp!="\n" && i<s.size() && tmp!=" "){
            num_str = num_str + tmp;
            i++;
            tmp = s.substr(i,1);
        }




        num = stol(num_str);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    
    answer = to_string(v[0]) + " " + to_string(v.back());
    return answer;
}