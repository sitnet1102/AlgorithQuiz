#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector <int>> v;
int min;
bool check = true;
vector<int> isused;     // 스타트 팀에 속하는지 여부 
vector<int> s;          // n/2 크기 벡터    스타트 팀에 속하는 팀원 


void func(int k){
    if(k==N/2){

        return;
    }

    for(int i=0;i<){

    }

}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        vector<int> a;
        for(int j=0;j<N;j++){
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        v.push_back(a);
        isused.push_back(0);
        if(!i%2){
            s.push_back(-1);
        }
    }

    func(0);

    return 0;
}