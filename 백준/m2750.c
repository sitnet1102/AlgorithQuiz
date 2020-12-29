#include <stdio.h>

// bubble sort
int main() {
    int N;
    int num[1000];
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }

    for(int i=0;i<N-1;i++){
        int tmp, a;
        a = i;
        for(int j=i+1;j<N;j++){
            if(num[a] > num[j]){
                a = j;
            }
        }
        tmp = num[a];
        num[a] = num[i];
        num[i] = tmp;
    }

    for(int i=0;i<N;i++){
        printf("%d\n", num[i]);
    }
    return 0;
}