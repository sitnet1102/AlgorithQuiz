#include <stdio.h>

int main() {
    int x, y, w, h;
    int a[4], min;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    a[0] = w - x;
    a[1] = h - y;
    a[2] = x;
    a[3] = y;

    min = a[0];
    for(int i=0; i<4; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    printf("%d\n", min);
    return 0;
}