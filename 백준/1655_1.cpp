#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main () {
    int N;
    vector<int> ans;
    priority_queue<int, vector<int>, less<int>> max;    // 작은쪽
    priority_queue<int, vector<int>, greater<int>> min; // 큰쪽
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        if(max.empty()){
            max.push(tmp);
        }else if(min.empty()){
            if(max.top() > tmp){
                min.push(max.top());
                max.pop();
                max.push(tmp);
            }else{
                min.push(tmp);
            }
        }else{
            min.push(tmp);
            int a = max.top();
            int b = min.top();
            if(min.size() > max.size()){
                min.pop();
                max.push(b);
            }else if(a>b){
                max.pop();
                min.pop();
                max.push(b);
                min.push(a);
            }
        }
        ans.push_back(max.top());
        /*   
        cout << "==============================\n";
        cout << max.size() << " " << min.size() << "\n";
        for(int j=0;j<ans.size();j++){
            cout << ans[j] << " ";
        }
        cout << "\n";
        */
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }

    return 0;
}