#include <iostream>
int main(){
    int n, i, j, rank;
    int arr_person[50][2];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d\n", &arr_person[i][0], &arr_person[i][1]);
    }
    for(i=0;i<n;i++){
        rank = 1;
        for(j=0;j<n;j++){
            if(j!=i){
                if(arr_person[i][0]<arr_person[j][0]){
                    if(arr_person[i][1]<arr_person[j][1]){
                        rank += 1;
                    }
                }            
            }
        }
        printf("%d ", rank);
    }
    
    return 0;
}