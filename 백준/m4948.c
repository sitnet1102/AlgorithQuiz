#include <stdio.h>
#include <math.h>

int prime[250000] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, };
int main() {
    int n, ans;
    float q;
    for (int i = 11; i < 250000; i++)
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
    scanf("%d",&n);
    while(n){
        ans = 0;
        for(int i=n+1;i<=2*n;i++){
            if(prime[i]){
                ans++;
            }
        }
        printf("%d\n", ans);

        
        scanf("%d",&n);
    }

    return 0;
}