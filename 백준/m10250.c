#include <stdio.h>

int main() {
    int T, H, W, N;
    int a, b, c;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d", &H, &W, &N);
        a = N % H;
        b = N / H + 1;
        if(a == 0){
            a = H;
            b--;
        }
        c = a * 100 + b;
        printf("%d\n", c);
    }

    return 0;
}