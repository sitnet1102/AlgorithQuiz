#include <stdio.h>

int main() {
    long int X;
    int i = 1;
    long long int num;
    int a;
    int out1, out2;
    scanf("%ld", &X);
    // sum(k) = k * (k+1) / 2
    while(1){
        num = i * (i+1) / 2;
        if(X <= num){
            a = i;
            break;
        }
        i++;
    }
    X = X - (a-1) * a / 2;
    if(a%2 == 0){
        out2 = a + 1 - X;
        out1 = X;
    }else{
        out1 = a + 1 - X;
        out2 = X;
    }
    printf("%d/%d\n", out1, out2);
    return 0;
}