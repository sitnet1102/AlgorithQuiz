#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int N;
    vector<int> v;
    vector<int> ans;
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        sort(v.begin(), v.end());
        ans.push_back(v[(v.size()-1)/2]);
    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }
    return 0;
}