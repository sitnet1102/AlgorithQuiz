#include <iostream>
#include <vector>
using namespace std;

int N;
int max_num;
bool check = true;
//int before;                 // 이전위치         
vector<vector<int> > v;
vector<int> x;              // 선택된 위치 

void func(int k){
    if(k == N){
        int num = 0;
        for(int i=0;i<N;i++){
            num = num + v[i][x[i]];
        }
        if(check){
            max_num = num;
            check = false;
        }else{
            if(max_num < num){
                max_num = num;
            }
        }

        return;
    }

    for(int i=0;i<4;i++){
        if(x.empty() || i != x[k-1]){
            x.push_back(i);
            func(k+1);
            x.pop_back();
        }
    }



}


int solution(vector<vector<int> > land)
{
    int answer = 0;
    N = land.size();
    v = land;
    func(0);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;
    //cout << land.size();

    return answer;
}