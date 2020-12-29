#include <stdio.h>

int main() {
    int a, b, c;
    int max, d, e;
    scanf("%d %d %d", &a, &b, &c);

    while(a){
        max = a;
        d = b;
        e = c;
        if(b>max){
            max = b;
            d = a;
            e = c;
        }
        if(c>max){
            max = c;
            d = a;
            e = b;
        }

        if(max * max == d * d + e * e){
            printf("right\n");
        }else{
            printf("wrong\n");
        }


        scanf("%d %d %d", &a, &b, &c);
    }




}