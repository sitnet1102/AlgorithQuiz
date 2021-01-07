#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

//vector<bool> prime;
bool prime[10000001] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, };
vector <int> v;
vector <bool> isused;
vector <int> s;
vector <int> p;
//int ans = 0;

void func(int k, int n){
    if(k == n){
        int tmp = 0;
        for(int i=0;i<s.size();i++){
            tmp = tmp*10 + s[i];
        }
        if(prime[tmp]){
            p.push_back(tmp);
            //ans++;
        }
        //cout << "tmp : " << tmp << " ans : " << ans << " k = " << k << "\n";
        return;
    }

    for(int i=0;i<v.size();i++){
        if(!isused[i]){
            isused[i] = 1;
            s.push_back(v[i]);
            func(k+1,n);
            isused[i] = 0;
            s.pop_back();
        }
    }
}


int solution(string numbers) {
    int answer = 0;
    float q;
    int N = 1;
    for(int i=0;i<numbers.size();i++){
        N = N * 10;
    }
    for (int i = 14; i < N; i++)
    {
        prime[i] = 1;
        q = sqrt(i);
        if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 11 == 0 || i % 13 == 0){
            prime[i] = 0;
        }else{
            for (int j = 17; j < i; j += 2)
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
        isused.push_back(0);
    }
    sort(v.begin(), v.end());
   
    /*
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
        cout << tmp << "-- tmp \n";
        if(prime[tmp]){
            answer ++;
        }
    }
    */
    for(int i=1;i<=numbers.size();i++){
        func(0,i);
    }
    //answer = ans;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()),p.end());
    /*
    for(int i=0;i<p.size();i++){
        cout << p[i] << " ";
    }
    cout << "\n";
    */
    answer = p.size();
    return answer;
}

int main () {

    string number;
    cin >> number;
    cout << solution(number);


    return 0;
}

/*

"7843"  12
"9999999"  0
"1276543"  1336
*/