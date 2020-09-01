#include <stdio.h>
#include <math.h>

int main () {
    int T;
    long long int x, y;
    
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%lld %lld", &x, &y);
        long long int num = y - x;
        long long int tmp;
        int a, b, c, d;
        int ans;
        tmp = sqrt(num);
        a = (int)tmp;
        /*
        while(1){
            tmp = j * j;
            
            if(tmp > num){
                a = j-1;
                break;
            }
            j++;
        }
        */
        b = num - a * a;
        c = b / a;
        d = b % a;
        if(d != 0){
            c++;
        }
        ans = a + a-1 + c;
        printf("%d\n", ans);
    }
    

    return 0;
}