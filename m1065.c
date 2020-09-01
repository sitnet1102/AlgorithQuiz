#include <stdio.h>

int check(int n){
    int tmp = n;
    int a[4];
    int b, x, y, t;
    t = 1;
    for(int i=0;i<4;i++){
        a[i] = tmp%10;
        tmp = tmp/10;
        if(!tmp){
            b = i;
            break;
        }
    }
    if(b < 2){
        return 1;
    }else{
        for(int i=0; i<b-1;i++){
            x = a[i] - a[i+1];
            y = a[i+1] - a[i+2];
            if(x == y){
                t++;
            }
        }
    }
    if(b == t){
        return 1;
    }
    return 0;
}


int main() {
    int n;
    int result = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        result += check(i+1);
    }

    printf("%d\n",result);

    return 0;
}