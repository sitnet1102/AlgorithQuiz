#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ans = 0;
int N;
int v[15];
int board[15][15] = {0,};
bool check(int num){
    
}


void func(int k){
    if(k == N){
        ans ++;
        return;
    }
    for(int i=1;i<=N;i++){
        if(!board[i][k]){
            v[k] = i;
            check(k);
            func(k+1);
            check(k-1);
        }
    }
}

int main(){
    cin >> N;
    func(0);
    cout << ans;
    return 0;
}