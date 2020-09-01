#include <stdio.h>
int F(int N, int x, int y){
    int t = N/3;
    int a, b, c, d;
    a = x / t;
    b = y / t;
    c = x % t;
    d = y % t;
    if(a == 1 && b == 1){
        return 0;
    }else if(N==3){
        if(x==1 && y==1){
            return 0;
        }else{
            return 1;
        }
    }else{
        return F(t, c, d);
    }


}

int main() {
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!F(N,i,j)){
                printf(" ");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}