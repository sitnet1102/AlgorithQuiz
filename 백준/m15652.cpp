#include <iostream>

using namespace std;

int N, M;
int v[10];
int isused[10];

void func(int k){
    if(k == M){
        for(int i=0;i<M;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=N;i++){
        if(k==0 || i >= v[k-1]){
            v[k] = i;
            func(k+1);
        }
    }
}

int main() {
    cin >> N >> M;
    func(0);
    return 0;
}