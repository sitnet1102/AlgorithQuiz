#include <stdio.h>
// A + (A - B) * i
int main () {
    long int A, B, V;
    int num;
    int a;
    scanf("%ld %ld %ld", &A, &B, &V);

    num = (V - A) / (A - B);
    a = (V - A) % (A - B);
    if(a){
        num++;
    }
    printf("%d\n", num+1);


    return 0;
}