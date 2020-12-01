#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    vector<int> v;
    int num;
    int tmp;

    cin >> num;
    for(int i=0;i<num;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    for(int i=0;i<num;i++){
        printf("%d\n", v[i]);
    }

    return 0;
}