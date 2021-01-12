#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main () {
    int N;
    vector<int> v;
    vector<int> ans;
    priority_queue<int, vector<int>, less<int>> max;    // 작은쪽
    priority_queue<int, vector<int>, greater<int>> min; // 큰쪽
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