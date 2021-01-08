#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = 0;
    sort(people.begin(),people.end());
    for(int i=people.size()-1;i>=0;i--){
        if(people[i] > limit - 40){
            n++;
        }else{
            break;
        }
    }
    for(int i=0;i<n;i++){   
        people.pop_back();
        answer ++;
    }
    for(int i=people.size()-1;i>0;i--){
        int index = -1;
        for(int j=0;j<people.size()-1;j++){
            if(people[i] + people[j] > limit){
                break;
            }else{
                index = j;
            }
        }
        people.pop_back();
        answer++;
        if(index != -1){
            people.erase(people.begin()+index);
            i--;
        }
    }
    if(people.size()==1){
        answer++;
    }
    return answer;
}


int main () {
    int n;
    vector<int> p;
    int l;

    cin >> n >> l;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }

    cout << solution(p,l);

    return 0;
}