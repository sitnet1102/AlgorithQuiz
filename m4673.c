#include <stdio.h>
int d(int n){
    int tmp = n;
    int result = n;
    while(1){
        result += tmp%10;
        tmp = tmp/10;
        if(tmp == 0){
            break;
        }
    }
    return result;
}

int main(){
    for(int i=1; i<10000; i++){
        for(int j=i/2; j<i;j++){
            if(d(j) == i){
                check[i] = 1;
                break;
            }
        }
    }

    for(int i=1; i<10000;i++){
        if(!check[i]){
            printf("%d\n",i);
        }
    }


    return 0;
}