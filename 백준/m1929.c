#include <stdio.h>
#include <math.h>
int prime[1000000] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, };
int main() {
    int M, N;
    float q;
    for (int i = 11; i < 1000001; i++)
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
    for (int i = M; i <= N; i++)
    {
        if(prime[i]){
            printf("%d\n",i);
        }
    }
    

    return 0;
}