#include <stdio.h>

int card[100]={0, };
int main(){
    int N, M;
    int max = 0;
    int tmp;
    scanf("%d %d", &N, &M);

    for(int i=0;i<N;i++){
        scanf("%d", &card[i]);
    }

    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                tmp = card[i] + card[j] + card[k];
                if(tmp > max && tmp <= M){
                    max = tmp;
                }
            }
        }
    }
    printf("%d\n", max);

    return 0;
}