#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


bool compare(string p, string p2){
    if(int(p.size()) == int(p2.size())){
        for(int i=0;i<int(p.size());i++){
            if(p[i] != p2[i]){
                return p[i] < p2[i];
            }
        }
        //N--;
    }
    return int(p.size()) < int(p2.size());

}

int main(){
    int N;
    vector <string> v;
    
    scanf("%d", &N);

    for(int i=0;i<N;i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
        //printf("%d\n", int(tmp.size()));
    }
    //printf("\n");
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0;i<v.size();i++){
        printf("%s\n", v[i].c_str());
    }
    //printf("%shi",v[N-1].c_str());

    return 0;
}