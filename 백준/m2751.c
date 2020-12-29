#include <stdio.h>
#include <stdlib.h>
// merge sorting
int N;
int* num;



int main(){
    
    scanf("%d", &N);
    num = (int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    quicksort(num, 0, N-1);
    for(int i=0;i<N;i++){
        printf("%d\n", num[i]);
    }
    return 0;
}