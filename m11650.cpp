#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<vector<int>> v;
    vector<int> v2;
    int x,y;
    
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d %d", &x, &y);
        v2.push_back(x);
        v2.push_back(y);
        v.push_back(v2);
        v2.empty();
    }

    

    return 0;
}