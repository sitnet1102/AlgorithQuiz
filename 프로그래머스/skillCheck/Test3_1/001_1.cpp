#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

bool comp(int a, int b){
    return a > b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int N = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    //cout << A[0] << " " << B[0];

    for(int i=0;i<N;i++){
        if(A.back() > B.back()){
            A.pop_back();
            B.erase(B.begin());
        }else if(A.back() == B.back()){
            A.pop_back();
            B.pop_back();
        }else{
            answer++;
            A.pop_back();
            B.pop_back();
        }

    }

    return answer;
}

// 47.6 / 50    정확성 40.5 (하나 틀림) , 효율성 7.1