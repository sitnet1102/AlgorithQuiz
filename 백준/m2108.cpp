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
    int x1;
    vector<int> v;
    vector<int> t;
    int checkarr[8001] = {0};
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
        checkarr[4000+v[i]]++;
    }
     
    x = double(sum) / double(n);
    x1 = int(round(x));
    //cout << "x = " << x << "\nsum = " << sum << endl;
    //cout << round(x) << endl;
    printf("%d\n", x1);

    // 중앙값 

    //cout << v[n/2] << endl;
    printf("%d\n", v[n/2]);
    
    
    // 최빈값
    /*
    index[1] = 0;
    if(n==1){
        //cout << v[0] << endl;
        printf("%d\n", v[0]);
    }else if(t.size()==0){
        //cout << v[1] << endl;
        printf("%d\n", v[1]);
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
        //cout << v[index[0]] << endl;
        printf("%d\n", v[index[0]]);
    }
    */
    index[0] = v[0];
    index[1] = 0;

    for(int i=0;i<8001;i++){
        if(checkarr[i] > max){
            max = checkarr[i];
            index[0] = i-4000;
            index[1] = 0;
        }else if(checkarr[i]==max){
            if(index[1]==0){
                index[0] = i-4000;
                index[1]++;
            }
        }
    }
    printf("%d\n", index[0]);

    // 범위
    //cout << v[n-1] - v[0] << endl;
    printf("%d\n", v[n-1] - v[0]);
    return 0;
}
