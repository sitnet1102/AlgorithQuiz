// 퀸의 위치를 저장한 곳에서 체크하는 방식 

#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int N;
int v[15];

bool possible(int x, int y, int k){
    for(int i=1;i<=k;i++){
        if(v[i] == x) return false;
        if(abs(v[i] - x) == abs(i - y)) return false;
    }

    return true;
}

void func(int k){
    if(k == N+1){
        ans ++;
        return;
    }
    for(int i=1;i<=N;i++){
        v[k] = i;
        if(possible(i, k, k-1)){
            func(k+1);
        }
    }
}

int main(){
    cin >> N;
    func(1);
    cout << ans;
    return 0;
}