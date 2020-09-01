#include <stdio.h>

int main(){
    float c, n, a;
    float avg;
    int score[1000];
    float result[1000];
    scanf("%f",&c);
    for(int i=0;i<c;i++){
        scanf("%f",&n);
        avg = 0;
        a = 0;
        for(int j=0;j<n;j++){
            scanf("%d",&score[j]);
            avg += score[j];
        }
        avg = avg/n;
        for(int j=0;j<n;j++){
            if(score[j]>avg){
                a++;
            }
        }
        result[i] = 100 * a / n;
    }

    for(int i=0;i<c;i++){
        printf("%.3f%%\n",result[i]);
    }

    return 0;
}