#include <stdio.h>

int main () {
    int arr[15][15];
    int T, k, n;
    for(int i=0;i<15;i++){
        arr[0][i] = i;
    }
    for(int i=1;i<15;i++){
        
        arr[i][1] = arr[i-1][1];
        
        for(int j=2;j<15;j++){
            arr[i][j] = arr[i][j-1] + arr[i-1][j];
        }
    }
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d", &k, &n);
        printf("%d\n", arr[k][n]);
    }
    return 0;
}