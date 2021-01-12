#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> loca;
    for(int i=0;i<priorities.size();i++){
        loca.push_back(i);
    }
    while(!priorities.empty()){
        bool check = true;
        int tmp = priorities[0];
        int tmp_index = loca[0];
        priorities.erase(priorities.begin());
        loca.erase(loca.begin());
        for(int i=0;i<priorities.size();i++){
            if(tmp < priorities[i]){
                priorities.push_back(tmp);
                loca.push_back(tmp_index);
                check = false;
                break;
            }
        }
        if(check){
            answer++;
            if(tmp_index == location){
                break;
            }
        }
    }
    return answer;
}