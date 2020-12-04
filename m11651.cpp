#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair <int, int> p, pair<int,int> p2){
    if(p.second == p2.second){
        return p.first < p2.first;
    }

    return p.second < p2.second;
}
int main(){
    int N;
    vector<pair <int, int>> v;
    
    int x,y;
    
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        pair<int, int> v2;
        scanf("%d %d", &x, &y);
        v2.first = x;
        v2.second = y;
        v.push_back(v2);
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<N;i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}