// board를 사용하여 update 해주는 방식으로 진행
// check 함수에서 O(n^2)이 걸려서 시간 복잡도에서 부족 

#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int N;
int v[15];
int board[15][15] = {0,};       // [x][y]

void ppp(){
    printf("================ ans = %d\n",ans);
    for(int i=0;i<15;i++){
        printf("%d",v[i]);
    }
    printf("\n");
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            printf("%d", board[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}


void check(int num){
    //printf("====================== k = %d\n", num);
    // 체크 보드 초기화
    for(int i=1;i<15;i++){
        for(int j=1;j<15;j++){
            board[i][j] = 0;
        }        
    }
    // num 까지 채워진 퀸의 위치에 따라서 놓을 수 없는 위치 체크
    // 퀸이 있으면 1, 퀀이 공격할 수 있는 위치 이지만 비어있으면 2
    for(int i=1;i<=num;i++){
        for(int j=1;j<=N;j++){
            // 같은 x 줄 체크
            board[j][i] = 2;
            // 같은 y 줄 체크 
            board[v[i]][j] = 2;
            // 양의 대각선 체크
            if(v[i]+j <= N && i+j <= N)
                board[v[i]+j][i+j] = 2;
            // 음의 대각선 체크 
            if(v[i]-j >=1 && i+j <= N)
                board[v[i]-j][i+j] = 2;
        }               
    }
    for(int i=1;i<=num;i++){
        // 퀸 위치 1
        board[v[i]][i] = 1;
    }
    //ppp();
}



void func(int k){
    if(k == N){
        // 퀸이 개수에 맞는지 확인 
        int tmp = 0;
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if (board[j][i] == 1 || board[j][i] == 0){
                    tmp ++;
                }
            }
        }
        if(tmp == N)
            ans ++;
        
        //ans ++;
        return;
    }
    for(int i=1;i<=N;i++){
        if(!board[i][k]){
            v[k] = i;
            check(k);
            func(k+1);
            check(k-1);
        }
    }
}

int main(){
    cin >> N;
    func(1);
    cout << ans;
    return 0;
}