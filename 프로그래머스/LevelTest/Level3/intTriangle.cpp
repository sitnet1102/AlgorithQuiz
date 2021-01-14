#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int num = triangle.size();
    vector<int> v, w;
    for(int i=0;i<num;i++){
        v.push_back(0);
        for(int j=0;j<triangle[i].size();j++){
            int r = 0;
            int l = 0;
            int alpha;
            if(i!=0){
                if(j!=0){
                    l = w[j-1];
                }
                if(j!=triangle[i].size()-1){
                    r = w[j];
                }
            }
            alpha = l;
            if(r>l){
                alpha=r;
            }
            v[j] = triangle[i][j] + alpha;
        }
        w = v;
    }    
    sort(v.begin(), v.end(), cmp);
    answer = v[0];
    return answer;
}