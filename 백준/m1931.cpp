#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> v;
    int n;

    cin >> n;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        int a, b;
        cin >> a >> b;
        tmp.push_back(a);
        tmp.push_back(b);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        cout << v[i][0] << " "<< v[i][1] << "\n";
    }

    return 0;
}