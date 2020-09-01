#include <stdio.h>
#include <math.h>

int prime[10001] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, };
int main() {
    int T, n, a;
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
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        for (int j = n/2; j > 0 ; j--)
        {
            if(prime[j] == 1 && prime[n-j] == 1){
                a = j;
                break;
            }
        }
        printf("%d %d\n", a, n-a);
    }
    

    return 0;
}