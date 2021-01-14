#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> a, b;
    // 0번째 집을 포함 하는 경우        마지막 포함 안함
    a.push_back(money[0]);
    a.push_back(money[0]);
    for(int i=2;i<money.size()-1;i++){
        int tmp = a[i-1];
        if(a[i-1] < money[i]+a[i-2]){
            tmp = money[i]+a[i-2];
        }
        cout << tmp << " ";
        a.push_back(tmp);
    }
    cout << "\n";
    
    // 0번째 집을 포함 하는 않는 경우
    b.push_back(0);
    b.push_back(money[1]);
    for(int i=2;i<money.size();i++){
        int tmp = b[i-1];
        if(b[i-1] < money[i]+b[i-2]){
            tmp = money[i]+b[i-2];
        }
        b.push_back(tmp);
        cout << tmp << " ";
    }
    cout << "\n";
    answer = a.back();
    if(b.back() > a.back()){
        answer = b.back();
    }

    return answer;
}


/*
    1000 1 0 1 2 1000 0
    1000 0 1000 



*/