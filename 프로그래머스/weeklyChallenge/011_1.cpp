#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int maxX = 0;
    int maxY = 0;
    vector<vector<int>> board;
    //vector<vector<int>> dir = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=0;i<rectangle.size();i++){
        if(rectangle[i][2] > maxX){
            maxX = rectangle[i][2];
        }
        if(rectangle[i][3] > maxY){
            maxY = rectangle[i][3];
        }
    }
    
    for(int y=0;y<=maxY*2+1;y++){
        vector<int> tmp;
        for(int x=0;x<=maxX*2+1;x++){
            tmp.push_back(0);
        }
        board.push_back(tmp);
    }
    
    for(int i=0;i<rectangle.size();i++){
        for(int y=rectangle[i][1]*2;y<=rectangle[i][3]*2;y++){
            for(int x=rectangle[i][0]*2;x<=rectangle[i][2]*2;x++){
                board[y][x] = 1;
            }
        }
    }
    /*
    for(int i=board.size()-1;i>=0;i--){
        for(int j=0;j<board[i].size();j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    */
    /*
        만들어진 보드 위에 시작점에서 우선 확인 
        4방향을 확인해서 두 방향 확인 // 예외 -> 4방향 모두 1인경우 -> 8방향 찾기 
        두 방향으로 각각 돌면서 아이템과 만나는 거리를 기록
        두 기록 중에서 작은 것을 리턴 
    */
    int curX = characterX*2;
    int curY = characterY*2;
    int max1 = 0;
    int max2 = 0;
    /*
    for(int i=0;i<dir.size();i++){
        d.push_back(board[curY+dir[i][1]][curX+dir[i][0]]);
    }
    for(int i=0;i<d.size();i++){
        cout << d[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<4;i++){
        if(d[i%4] == 1 & d[(i+1)%4] == 0){
            cout << curX + dir[i][0] << " " << curY + dir[i][1];
        }
    }
    
    
    */
    
    while(curX != itemX*2 || curY != itemY*2){
        //cout << curX << " " << curY << "  ";
        vector<int> d;
        for(int i=0;i<dir.size();i++){
            d.push_back(board[curY+dir[i][1]][curX+dir[i][0]]);
        }
        for(int i=0;i<d.size();i++){
            if(d[i%8] == 1 & d[(i+1)%8] == 0){
                //cout << curX + dir[i][0] << " " << curY + dir[i][1];
                if(i%2 == 0){
                    curX = curX + dir[i][0];
                    curY = curY + dir[i][1];
                }else{
                    curX = curX + dir[(i+7)%8][0];
                    curY = curY + dir[(i+7)%8][1];
                }
                max1 ++;
                break;
            }
        }
    }
    //cout << "\n" << max1 << "\n";
    
    curX = characterX*2;
    curY = characterY*2;
    /*
    while(curX != itemX*2 || curY != itemY*2){
        //cout << curX << " " << curY << "  ";
        vector<int> d;
        for(int i=dir.size()-1;i>=0;i--){
            d.push_back(board[curY+dir[i][1]][curX+dir[i][0]]);
        }
        for(int i=d.size()-1;i>=0;i--){
            if(d[i%8] == 1 & d[(i-1)%8] == 0){
                //cout << curX + dir[i][0] << " " << curY + dir[i][1];
                if(i%2 == 0){
                    curX = curX + dir[i][0];
                    curY = curY + dir[i][1];
                }else{
                    curX = curX + dir[(i+1)%8][0];
                    curY = curY + dir[(i+1)%8][1];
                }
                max2 ++;
                break;
            }
        }
    }
    */
    answer = max1/2;
    
    return answer;
}