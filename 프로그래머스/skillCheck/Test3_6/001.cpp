#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<int>> v;
    vector<vector<int>> w;
    
    for(int i=0;i<m;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            //cout << city_map[i][j] << " ";
            tmp.push_back(0);
        }
        //cout << "\n";
        v.push_back(tmp);
        w.push_back(tmp);
    }
    //cout << "\n";
    /*
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    */
    v[0][0] = 1;
    w[0][0] = 1;
    for(int i=0;i<m+n-1;i++){
        for(int j=0;j<=i;j++){
            int x=j;
            int y=i-j;
            //cout << x << " " << y << "\n";
            if(x < m && y < n){
                if(city_map[x][y] == 0){
                    if(x > 0){
                        if(city_map[x-1][y] != 2){
                            v[x][y] = v[x][y] + v[x-1][y];
                        }else{
                            
                        }
                    }
                    if(y > 0){
                        if(city_map[x][y-1] != 2){
                            v[x][y] = v[x][y] + v[x][y-1];
                        }else{
                            
                        }
                    }
                }else if(city_map[x][y] == 1){
                    
                }else if(city_map[x][y] == 2){
                    if(x > 0){
                        v[x][y] = v[x-1][y];
                    }
                    if(y > 0){
                        w[x][y] = v
                    }
                }
            }
        }
    }
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    answer = answer / MOD;
    return answer;
}