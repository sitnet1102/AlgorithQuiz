#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> v;
    vector<vector<int> > camera;
    v.push_back(routes[0][0]);
    v.push_back(routes[0][1]);
    sort(routes.begin(), routes.end(), comp);
    for(int i=0;i<routes.size();i++){
        cout << "=======================================\n";
        cout << routes[i][0] << " " << routes[i][1] << "\n";
        cout << "---------------------------------------\n";
        cout << "v = " << v[0] << " " << v[1] << "\n";
        cout << "camera : " << camera.size() << "\n";
        for(int j=0;j<camera.size();j++){
            cout << camera[j][0] << " " << camera[j][1] << "\n";
        }
        if(v[1] < routes[i][0]){
            camera.push_back(v);
            v[0] = routes[i][0];
            v[1] = routes[i][1];
        }else{
            v[0] = routes[i][0];
            if(v[1] > routes[i][1]){
                v[1] = routes[i][1];
            }
        }
    }
    answer = camera.size() + 1;

    return answer;
}

/*
    for(int i=0;i<routes.size();i++){
        cout << routes[i][0] << " " << routes[i][1] << "\n";
    }


*/