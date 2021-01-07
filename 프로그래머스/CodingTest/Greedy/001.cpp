#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    /*
    for(int i=0;i<lost.size();i++){
        cout << lost[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<reserve.size();i++){
        cout << reserve[i] << " ";
    }
    cout << "\n";
    */
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i] == reserve[j]){
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                answer ++;
            }
        }
    }
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            //cout << "=======================================\n";
            //cout << "lost : " << lost[i] << " reserve : " << reserve[j] << "\n";

            if(lost[i] == reserve[j]+1 || lost[i] == reserve[j]-1){
                reserve.erase(reserve.begin() + j);
                answer ++;
                //cout << answer << "\n";
                break;
            }
        }
    }
    return answer;
}

//5, [1,2,4,5] [2,3,4] -> 3
//3, [1,2], [2,3] -> 2
//Lost = {10,16,19,20,24,26,27};
//Reserve = {4,7,8,10,13,14,16,17,18,19,21,22,23,24,25,26,27};

/*
int main(){
    int n, a, b;
    vector <int> l, r;

    cin >> n >> a >> b;
    for(int i=0;i<a;i++){
        int tmp;
        cin >> tmp;
        l.push_back(tmp);
    }
    for(int i=0;i<b;i++){
        int tmp;
        cin >> tmp;
        r.push_back(tmp);
    }

    cout << solution(n,l,r);
    return 0;
}
*/

int main(){
    int n = 27;
    vector <int> l, r;
    l.push_back(10);
    l.push_back(16);
    l.push_back(19);
    l.push_back(20);
    l.push_back(24);
    l.push_back(26);
    l.push_back(27);

    r.push_back(4);
    r.push_back(7);
    r.push_back(8);
    r.push_back(10);
    r.push_back(13);
    r.push_back(14);
    r.push_back(16);
    r.push_back(17);
    r.push_back(18);
    r.push_back(19);
    r.push_back(21);
    r.push_back(22);
    r.push_back(23);
    r.push_back(24);
    r.push_back(25);
    r.push_back(26);
    r.push_back(27);

    cout << solution(n,l,r);
    return 0;
}