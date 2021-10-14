#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool func(vector<long long> a, vector<long long> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<vector<long long>> v;
    vector<long long> Max;
    vector<long long> Min;
    
    for(int i=0;i<line.size()-1;i++){
        for(int j=i+1;j<line.size();j++){
            vector<long long> node;
            vector<int> L1 = line[i];
            vector<int> L2 = line[j];
            
            long long tmpNum = (long long)L1[0] * (long long)L2[1] - (long long)L1[1] * (long long)L2[0];
            long long xNum = (long long)L1[1] * (long long)L2[2] - (long long)L1[2] * (long long)L2[1];
            long long yNum = (long long)L1[2] * (long long)L2[0] - (long long)L1[0] * (long long)L2[2];
            double x, y;
            if(tmpNum != 0){
                x = (double)xNum / (double)tmpNum;
                y = (double)yNum / (double)tmpNum;
               if(x-(long long)x == 0 && y-(long long)y == 0){
                   cout << x << " " << y << "\n";
                   node.push_back((long long)x);
                   node.push_back((long long)y);
                   v.push_back(node);
               }
            }
        }
    }
    sort(v.begin(),v.end(),func);
    v.erase(unique(v.begin(),v.end()),v.end());
    Max = v[0];
    Min = v[0];
    for(int i=0;i<v.size();i++){
        if(Max[0] < v[i][0]){
            Max[0] = v[i][0];
        }
        if(Max[1] < v[i][1]){
            Max[1] = v[i][1];
        }
        if(Min[0] > v[i][0]){
            Min[0] = v[i][0];
        }
        if(Min[1] > v[i][1]){
            Min[1] = v[i][1];
        }
    }
    for(long long i=Min[1];i<=Max[1];i++){
        string tmp = "";
        for(long long j=Min[0];j<=Max[0];j++){
            tmp = tmp + ".";
        }
        answer.push_back(tmp);
    }
    cout << Min[0] << " " << Min[1] << "\n";
    cout << Max[0] << " " << Max[1] << "\n";
    for(int i=0;i<v.size();i++){
        answer[Max[1]-v[i][1]][v[i][0]-Min[0]] = '*';
        //cout << -v[i][1]+zero[1] << " " << v[i][0]-zero[0] << "\n";
    }
    return answer;
}