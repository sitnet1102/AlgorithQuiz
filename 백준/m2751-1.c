#include <stdio.h>
#include <stdlib.h>
int N;
int* num;
int partition(int* arr, int lo, int hi){
    int pivot = arr[hi];
    int i = lo;
    int tmp;
    for(int j=lo;j<hi;j++){
        if(arr[j]<pivot){
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i ++;
        }
    }
    tmp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = tmp;
    return i;     
}
void quicksort(int* arr, int lo, int hi){
    if(lo < hi){
        int p = partition(arr, lo, hi);
        quicksort(arr, lo, p-1);
        quicksort(arr, p+1, hi);
    }
}


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