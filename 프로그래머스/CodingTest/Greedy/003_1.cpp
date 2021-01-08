#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector <int> v;
    bool check = true;
    // 순서대로 돌면서 앞부터 증가하면 앞에것 지우기

    for(int i=0;i<k;i++){
        for(int j=0;j<number.size()-1;j++){
            int a = 1;
            for(int x=0;x<v.size();x++){
                if(v[x] == j){
                    goto Loop;
                }
                if(v[x] == j+a){
                    a++;
                }
            }
            /*
            cout << "v : ";
            for(int y=0;y<v.size();y++){
                cout << v[y] << " ";
            }
            cout << "\n";
            */
            if(number[j] < number[j+a]){
                v.push_back(j);
                //cout << "number : " << number << "\n";
                sort(v.begin(), v.end());
                break;
            }
            if(j == number.size()-v.size()-2){
                //number = number.substr(0, number.size()-1);
                v.push_back(j);
                sort(v.begin(), v.end());
                break;
            }
            //cout << "--------------\n";
            //cout << a << " " << b << "\n";
            Loop :
            ;
        }
    }
    /*
    for(int y=0;y<v.size();y++){
        cout << v[y] << " ";
    }
    cout << "\n";
    */

    for(int i=0;i<number.size();i++){
        bool c = true;
        for(int j=0;j<v.size();j++){
            if(i == v[j]){
                c = false;
            }
        }
        if(c){
            answer = answer + number[i];
        }
    }
 
    //answer = number;


    return answer;
}


int main () {
    string number;
    int k;
    cin >> number;
    cin >> k;
    cout << solution(number, k);

    return 0;
}