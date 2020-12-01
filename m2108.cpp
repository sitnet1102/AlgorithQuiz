#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, tmp;
    long long int sum = 0;
    int max = 0;
    int index[2];
    int tmpMax = 0;
    long double x;
    vector<int> v;
    vector<int> t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    /*
    for(int i=0;i<n;i++){
        cout << v[i] << "\n";
    }
    cout << v.size();
    */
    // 산술 평균 
    for(int i=0;i<n;i++){
        sum += v[i];
        if(i!=0 && v[i] == v[i-1]){
            t.push_back(i);
        }
    }
     
    x = double(sum) / double(n);
    //cout << "x = " << x << "\nsum = " << sum << endl;
    cout << round(x) << endl;

    // 중앙값 
    if(n%2 == 0){
        cout << v[n/2 -1] << endl;
    }else{
        cout << v[n/2] << endl;
    }
    
    // 최빈값
    index[1] = 0;
    if(n==1){
        cout << v[0] << endl;
    }else if(t.size()==0){
        cout << v[1] << endl;
    }else{
        for(int i=0;i<t.size();i++){
            if(i==0){
                index[0] = t[0];
            }else if(i==1){
                index[0] = t[1];
            }else if(t[i] == t[i-1]+1){
                tmpMax ++;
                if(max < tmpMax){
                    max = tmpMax;
                    index[0] = t[i];
                    index[1] = 0;
                }else if(max == tmpMax){
                    if(index[1] == 0){
                        index[0] = t[i];
                        index[1] = 1;
                    }
                }
            }
        }
        cout << v[index[0]] << endl;
    }

    // 범위
    cout << v[n-1] - v[0] << endl;

    return 0;
}
