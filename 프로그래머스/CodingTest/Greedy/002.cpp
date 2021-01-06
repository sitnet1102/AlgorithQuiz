#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

//vector<bool> prime;
bool prime[10000001] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, };

int solution(string numbers) {
    int answer = 0;
    vector <int> v;
    float q;
    int N = 1;
    for(int i=0;i<numbers.size();i++){
        N = N * 10;
    }
    for (int i = 13; i < N; i++)
    {
        prime[i] = 1;
        q = sqrt(i);
        if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 11 == 0 || i % 13 == 0){
            prime[i] = 0;
        }else{
            for (int j = 3; j < i; j += 2)
            {
                if(j<=q){
                    if(prime[j]){
                        if(i%j == 0){
                            prime[i] = 0;
                        }
                    }
                }else{
                    break;
                }
            }
        }
        
    }

    for(int i=0;i<numbers.size();i++){
        int tmp;
        tmp = stoi(numbers.substr(i,1));
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<numbers.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    for(int i=1;i<=numbers.size();i++){
        int tmp = 0;
        for(int k=0;k<i;k++){
            for(int j=0;j<v.size();j++){
                tmp = tmp * 10 + v[j];
            }
        }
        if(prime[tmp]){
            answer ++;
        }
    }


    return answer;
} 