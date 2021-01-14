#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> v;
    for(int i=0;i<n+2;i++){
        vector<int> tmp_v;
        for(int j=0;j<m+2;j++){
            int tmp = 0;
            if(i==0 || j==0 || i==n+1 || j==m+1){
                tmp = -1;
            }
            tmp_v.push_back(tmp);
        }
        v.push_back(tmp_v);
    }
    v[1][1] = 1; 
    //v[n][m] = 0; 
    for(int i=0;i<puddles.size();i++){
        v[puddles[i][1]][puddles[i][0]] = -1;
    }
    

    for(int i=2;i<=m+n;i++){
        for(int j=1;j<i;j++){
            int x, y;
            int left, up;
            x = j;
            y = i-j;
            if(x>m){
                continue;
            }
            if(y>n){
                continue;
            }
            if(v[y][x] == -1){
                continue;
            }
            left = v[y][x-1]; 
            up = v[y-1][x];
            if(left == -1){
                left = 0;
            }
            if(up == -1){
                up = 0;
            }
            v[y][x] = (v[y][x] + left + up) % 1000000007;
        }
    }
    //////////
    /*
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    */
    ////////////
    answer = v[n][m] % 1000000007;
    return answer;
}