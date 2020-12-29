#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<vector<int>> v;
    
    int x,y;
    
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        vector<int> v2;
        scanf("%d %d", &x, &y);
        v2.push_back(x);
        v2.push_back(y);
        v.push_back(v2);
    }
    //printf("\n");
    /*
    for(int i=0;i<N;i++){
        printf("%d %d\n", v[i][0], v[i][1]);
    }
    
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(v[i][0] > v[j][0]){
                x = v[i][0];
                y = v[i][1];
                v[i][0] = v[j][0];
                v[i][1] = v[j][1];
                v[j][0] = x;
                v[j][1] = y;
            }else if(v[i][0] == v[j][0]){
                if(v[i][1] > v[j][1]){                    
                    y = v[i][1];                    
                    v[i][1] = v[j][1];                    
                    v[j][1] = y;
                }
            }
        }       
    }
    */
    //printf("\n");
    sort(v.begin(), v.end());
    for(int i=0;i<N;i++){
        printf("%d %d\n", v[i][0], v[i][1]);
    }

    return 0;
}