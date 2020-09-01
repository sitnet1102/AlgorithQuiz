#include <stdio.h>

int main() {
    int a[3], b[3];
    int A, B;

    scanf("%d %d", &A, &B);

    for(int i=0; i<3; i++){
        a[i] = A%10;
        b[i] = B%10;
        A = A/10;
        B = B/10;
    }

    A = 0; B = 0;

    A = 100*a[0] + 10*a[1] + a[2];
    B = 100*b[0] + 10*b[1] + b[2];

    if(A > B){
        printf("%d\n", A);
    }else {
        printf("%d\n", B);
    }


    return 0;
}