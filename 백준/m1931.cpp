#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[1] == b[1]){
        a[0] < b[0];
    }
    return a[1] < b[1];
}

int main(){
    vector<vector<int>> v;
    vector<vector<int>> ans;
    int n;
    int start = -1;
    int answer = 0;

    cin >> n;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        int a, b;
        cin >> a >> b;
        tmp.push_back(a);
        tmp.push_back(b);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);
    /*
    for(int i=0;i<v.size();i++){
        cout << v[i][0] << " "<< v[i][1] << "\n";
    }
    */
    for(int i=0;i<n;i++){
        if(v[i][0] > start){
            start = v[i][1];
            answer ++;
            ans.push_back(v[i]);
        }
    }
    /*
    cout <<"\nans ======== \n";
    for(int i=0;i<ans.size();i++){
        cout << ans[i][0] << " "<< ans[i][1] << "\n";
    }
    */
    cout << answer << "\n";

    return 0;
}