#include <stdio.h>
int F(int n){
    if(n>=2){
        return F(n-1) + F(n-2);
    }else if(n==1){
        return 1;
    }else if(n==0){
        return 0;
    }
    return -1;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",F(n));

    return 0;
}