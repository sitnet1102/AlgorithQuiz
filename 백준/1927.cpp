#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main () {
    priority_queue<int, vector<int>, greater<int> > pq;
    int N;
    vector <int> v;
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            if(pq.empty()){
                v.push_back(0);
                //cout << 0 << "\n";
            }else{
                v.push_back(pq.top());
                //cout << pq.top() << "\n";
                pq.pop();
            }
        }else{
            pq.push(tmp);
        }
    }

    //cout << "\n";
    for(int i=0;i<v.size();i++){
        cout << v[i] << "\n";
    }

    return 0;
}