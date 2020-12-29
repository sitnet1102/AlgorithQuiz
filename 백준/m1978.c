#include <stdio.h>
#include <math.h>

int prime[1001] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, };
int main() {
    int N, a, ans;
    float q;
    for (int i = 11; i < 1001; i++)
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
    /*
    for(int i=1; i<1002; i++){
        printf("%d ", prime[i]);
        if(i%10 == 0){
            printf("\n");
        }
    }
    */
    ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        if(prime[a] == 1){
            ans++;
        }
    }
    
    printf("%d\n",ans);
    


    return 0;
}