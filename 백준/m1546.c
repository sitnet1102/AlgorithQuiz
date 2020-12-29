#include <stdio.h>

int main(){
    float m = 0;
    float score[1000] = {0,};
    int n;
    float a;
    float result = 0;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%f", &score[i]);
        if(m < score[i]){
            m = score[i];
        }
    }
    
    for(int i=0;i<n;i++){
        a = 100 * score[i] / m;
        result += a;
        //printf("%f\n", a);
    }
    //printf("m = %f, n = %d, result = %f\n ", m,n,result);
    printf("%f\n",result/n);
    return 0;
}