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