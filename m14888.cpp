#include <iostream>
#include <vector>

using namespace std;

int N;
int A[4];
int max, min;
vector<int> v;
vector<int> 

void func(int k){
    if(k == N){
        for(int i=0;i<N;i++){
            cout << v[i] << ' ';
        }
        cout <<'\n';
    }
    for(int i=1;i<=N;i++){
        if(!isused[i] && (i > v[k-1] || k == 0)){
            v[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}


int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<4;i++){
        cin >> A[i];
    }

    func(0);
    return 0;
}