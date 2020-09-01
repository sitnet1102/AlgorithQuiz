#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, r1, x2, y2, r2, T;
    double d, a;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        d = sqrt(d);
        a = r1 - r2;
        a = a * a;
        a = sqrt(a);
        if(x1 == x2 && y1 == y2 && r1 == r2){
            printf("-1\n");
        }else if(x1 == x2 && y1 == y2 && r1 != r2){
            printf("0\n");
        }else if(d > r1 + r2){
            printf("0\n");
        }else if(d == r1 + r2){
            printf("1\n");
        }else if(d == a){
            printf("1\n");
        }else if(d < a){
            printf("0\n");
        }else{
            printf("2\n");
        }
    }

    return 0;
}