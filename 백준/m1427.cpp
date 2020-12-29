#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N;
    int tmp;
    int v[10] = {0};
    scanf("%d\n", &N);

    for(int i=0;i<10;i++){
        if(N == 0){
            break;
        }
        tmp = N%10;
        N = N/10;
        v[tmp]++;
    }

    for(int i=9;i>-1;i--){
        for(int j=0;j<v[i];j++){
            printf("%d", i);
        }
    }



    return 0;
}