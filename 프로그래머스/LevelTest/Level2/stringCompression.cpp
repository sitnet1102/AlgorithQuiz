#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int length = 1;
    while(length <= s.size() / 2){
        vector<string> v;
        int num = s.size() / length;
        int n_str = 1;
        string tmp = "";
        /*
            */
        if(s.size() % length != 0){
            num ++;
        }
        for(int i=0;i<num;i++){
            v.push_back(s.substr(i*length,length));
        }
        /*
        cout << length << "============================\n";
        for(int i=0;i<num;i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        */
        for(int i=1;i<num;i++){
            if(v[i-1] != v[i]){
                if(n_str != 1){
                    tmp = tmp + to_string(n_str);
                }
                tmp = tmp + v[i-1];
                n_str = 1;
                if(i == num-1){
                    tmp = tmp + v[i];
                }
            }else{
                n_str++;
                if(i == num-1){
                    tmp = tmp + to_string(n_str);
                    tmp = tmp + v[i];
                }
            }
        }
        //cout << tmp << "\n";
        if(answer > tmp.size()){
            answer = tmp.size();
        }
        length ++;
    }
    return answer;
}