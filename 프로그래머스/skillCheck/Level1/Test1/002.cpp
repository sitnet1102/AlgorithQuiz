#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int N = board.size();
    vector<int> v;
    for(int i=0;i<moves.size();i++){
        int m = moves[i];
        for(int j=0;j<N;j++){
            if(board[j][m-1] != 0){
                int tmp = board[j][m-1];
                board[j][m-1] = 0;
                if(v.empty()){
                    v.push_back(tmp);
                }else{
                    int num = v.size();
                    if(v[num-1] == tmp){
                        v.pop_back();
                        answer++;
                        answer++;
                    }else{
                        v.push_back(tmp);
                    }
                }
                break;
            }

        }
        /////////////////////////
        /*
        printf("========================%d\n",i);
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                printf("%d ", board[a][b]);
            }
            printf("\n");
        }
        printf("\n");
        for(int a=0;a<v.size();a++){
            printf("%d ",v[a]);
        }
        printf("\n\n");
        */
        /////////////////////////
    }
    return answer;
}

int main(){
    //N*N 개 행렬 board[N][N], moves[x];
    //for(int i=0;)
    int N, M;
    cin >> N >> M;
    vector<vector<int>> board;
    vector<int> moves;
    for(int i=0;i<N;i++){
        vector<int> tmp;
        for(int j=0;j<N;j++){
            int tmp_num;
            cin >> tmp_num;
            tmp.push_back(tmp_num);
        }
        board.push_back(tmp);
    }
    for(int i=0;i<M;i++){
        int tmp;
        moves.push_back(tmp);
    }

    solution(board, moves);

    return 0;
}