#include <stdio.h>

int main() {
    double R, pi;
    double ans1,ans2;
    pi = 3.14159265358979;

    scanf("%6lf", &R);
    ans1 = R*R*pi;
    ans2 = 2*R*R;
    printf("%6lf\n", ans1);
    printf("%6lf\n", ans2);
    return 0;
}