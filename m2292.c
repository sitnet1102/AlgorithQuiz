#include <stdio.h>

int main () {
    int i=1;
    long int N;
    long long int num;
    scanf("%ld", &N);
    // 그룹당 개수 k * 6
    // 그룹 까지의 개수 sum(6k) = 3 * k * (k-1) + 1

    while(1){
        num = 3 * i * (i-1) + 1;
        //printf("[%lld]\n", num);
        if(N <= num){
            printf("%d\n", i);
            break;
        }
        i++;
    }

    return 0;
}