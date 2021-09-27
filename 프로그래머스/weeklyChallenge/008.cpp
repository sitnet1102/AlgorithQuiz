#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int a = 0;
    int b = 0;
    
    for(int i=0;i<sizes.size();i++){
        sort(sizes[i].begin(),sizes[i].end());
    }
    /*
    for(int i=0;i<sizes.size();i++){
        cout << sizes[i][0] << " " << sizes[i][1] << "\n";
    }
    */
    
    for(int i=0;i<sizes.size();i++){
        if(a < sizes[i][0]){
            a = sizes[i][0];
        }
        if(b < sizes[i][1]){
            b = sizes[i][1];
        }
    }
    answer = a * b;
    
    return answer;
}