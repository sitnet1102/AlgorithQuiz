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
    vector<vector<int>> v;
    vector<int> Max;
    vector<int> Min;
    vector<int> zero;
    
    for(int i=0;i<line.size()-1;i++){
        for(int j=i+1;j<line.size();j++){
            vector<int> node;
            vector<int> L1 = line[i];
            vector<int> L2 = line[j];
            vector<int> tmpL;
            double x, y;
            for(int k=0;k<L1.size();k++){
                int a = L1[k]*L2[0] - L2[k]*L1[0];
                tmpL.push_back(a);
            }
            /*
            cout << "--- " << L1[0] << " " << L1[1] << " " << L1[2] <<  "   ,   " << L2[0] << " " << L2[1] << " " << L2[2] << "\n";
            cout << tmpL[0] << " " << tmpL[1] << " " << tmpL[2] << "\n";
            */
            if(tmpL[1] == 0){
                break;
            }else{
                y = (-1) * (double)tmpL[2] / (double)tmpL[1];
                //cout << y << " " << y - (int)y << "\n";
                if(y-(int)y == 0){
                    if(L1[0] == 0){
                        x = (-1) * ( (double)L2[1]*y + (double)L2[2] ) / (double)L2[0];
                    }else{
                        x = (-1) * ( (double)L1[1]*y + (double)L1[2] ) / (double)L1[0];
                    }
                    
                    if(x-(int)x == 0){
                        node.push_back((int)x);
                        node.push_back((int)y);
                        v.push_back(node);
                    }
                    //cout << x << " \n"; 
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
        answer[-v[i][1]+zero[1]][v[i][0]+zero[0]] = '*';
    }
    /*
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << "\n";
    }
    */
    return answer;
}