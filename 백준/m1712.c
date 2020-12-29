#include <stdio.h>

int main() {
    int A, B, C;
    long long int num;
    int answer = -1;
    scanf("%d %d %d", &A, &B, &C);

    
    if(B > C){
        
    }else if(B == C){
        if(A >= 0){
            
        }
    }else{
        answer = A / (C-B);
        answer ++;
    }
    
    /*
    for(int i=0;;i++){
        num = A + (B - C) * i;
        //printf("[%d] price = %lld\n", i, num);
        if(B > C){
            printf("-1\n");
            break;
        }else if(B == C){
            if(A > 0){
                printf("-1\n");
                break;
            }
        }else{
            if(num < 0){
                printf("%d\n", i);
                break;
            }
        }
    }
    */
    
    printf("%d\n", answer);

    return 0;
}