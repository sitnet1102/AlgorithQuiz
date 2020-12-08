#include <stdio.h>
#include <iostream>

using namespace std;

int v[10];
//int isused[10];
int N, M;

void func(int k){
    if(k == M){
        for(int i=0;i<M;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=N;i++){
        v[k] = i;
        func(k+1);
    }
}




int main() {

    cin >> N >> M;

    func(0);

    return 0;
}