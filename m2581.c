#include <stdio.h>
#include <math.h>
int prime[10001] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, };
int main() {
    int M, N, sum, min;
    float q;
    for (int i = 11; i < 10001; i++)
    {
        prime[i] = 1;
        q = sqrt(i);
        if(i % 2 == 0){
            prime[i] = 0;
            goto Loop;
        }
        for (int j = 3; j < i; j += 2)
        {
            if(j<=q){
                if(prime[j]){
                    if(i%j == 0){
                        prime[i] = 0;
                    }
                }
            }else{
                break;
            }
        }
        Loop:
        ;
    }
    scanf("%d %d", &M, &N);
    min = N;
    sum = 0;
    for(int i=M;i<=N;i++){
        if(prime[i]){
            sum += i;
            if(i<min){
                min = i;
            }
        }
    }
    if(sum == 0){
        printf("-1\n");
    }else{
        printf("%d\n%d\n", sum, min);
    }
    return 0;
}