#include <stdio.h>
int P[3][20] = {0, };
int top[3] = {-1, -1, -1};
int K = 0;

void pp(){
    for(int i=0;i<3;i++){
        for(int j=0;j<20;j++){
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<3;i++){
        printf("%d ",top[i]);
    }
    printf("\n");
}

int Move(int a, int b){ // a = 처음 위치, b = 옮길 위치
    int tmp;
    if(top[a] == -1){
        return -1;
    }else{
        tmp = P[a][top[a]];
        P[a][top[a]] = 0;
        top[a]--;
        P[b][top[b]+1] = tmp;
        top[b]++;
        printf("%d %d\n", a+1 ,b+1);
        K ++;
    }
    return 0;
}

int F(int n, int a, int b, int c) { // a = 처음 위치, b = 옮길 위치
    int tmp;
    int result;
    if(n==1){
        result = Move(a, b);
    }else{
        F(n-1, a, c, b);
        Move(a, b);
        F(n-1, c, b, a);
    }
    //pp();
    return result;
}

int Fnum(int n){
    if(n == 1){
        return 1;
    }else{
        return 2 * Fnum(n-1) + 1;
    }

}

int main() {
    int N;
    scanf("%d", &N);

    for(int i=0;i<N;i++){
        P[0][i] = i+1;
        top[0] ++;
    }
    printf("%d\n", Fnum(N));
    F(N, 0, 2, 1);
    
   


    return 0;
}