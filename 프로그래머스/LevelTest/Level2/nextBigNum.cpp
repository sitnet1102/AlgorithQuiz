#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {   // 20자리 
    int answer = 0;
    vector<int> v;
    bool check = false;
    int index;

    while(n){
        int a = n%2;
        n = n/2;
        v.push_back(a);
    }

    for(int i=0;i<v.size();i++){
        if(v[i] == 0){
            check = true;
            index = i;
        }
    }
    if(check){  // 중간에 0이 있을 때
        

    }else{      // 중간에 0이 없을 때

    }

    for(int i=0;i<v.size();i++){
        cout << v[i];
    }

    return answer;
}

// 0 1 1 1 0 0 1