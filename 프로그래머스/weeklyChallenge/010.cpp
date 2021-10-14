#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool func(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<vector<long long>> v;
    vector<int> Max;
    vector<int> Min;
    vector<int> zero;
    
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
                /*
                cout << "--- " << L1[0] << " " << L1[1] << " " << L1[2] <<  "   ,   " << L2[0] << " " << L2[1] << " " << L2[2] << "\n";
                cout << x << " " << y << "\n";
                */
               if(x-(int)x == 0 && y-(int)y == 0){
                   node.push_back((long long)x);
                   node.push_back((long long)y);
                   v.push_back(node);
               }
            }
        }
    }
    
    sort(v.begin(),v.end(),func);
    v.erase(unique(v.begin(),v.end()),v.end());
    /*
    for(int i=0;i<v.size();i++){
        cout << v[i][0] << " " << v[i][1] << "\n";
    }
    */
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
    /*
    cout << "Max == " << Max[0] << " " << Max[1] << "\n";
    cout << "Min == " << Min[0] << " " << Min[1] << "\n";
    */
    for(int i=Min[1];i<=Max[1];i++){
        string tmp = "";
        for(int j=Min[0];j<=Max[0];j++){
            tmp = tmp + ".";
        }
        answer.push_back(tmp);
    }
    /*
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << "\n";
    }
    */
    zero.push_back((-1)*Min[0]);
    zero.push_back(Max[0]);
    for(int i=0;i<v.size();i++){
        //answer[-v[i][1]+zero[1]][v[i][0]+zero[0]] = '*';
        cout << -v[i][1]+zero[1] << " " << v[i][0]+zero[0] << "\n";
    }
    /*
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << "\n";
    }
    */
    return answer;
}