#include <stdio.h>
// 1 2 4 7 
int main() {
    int N;
    int n3, n5;
    int ans = -1;

    scanf("%d", &N);
    if(N == 1 || N == 2 || N == 4 || N == 7){
        goto Loop;
    }
    n5 = N / 5;
    n3 = 0;
    N = N % 5;
    while(n5){
        if(N%3 == 0){
            break;
        }
        n5--;
        N += 5;
    }

    n3 = N/3;
    ans = n5 + n3;

    Loop:
    printf("%d\n", ans);
    return 0;
}