#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int num = progresses.size();
    int now = 0;
    while(now != num){
        int tmp = 0;
        for(int i=now;i<num;i++){
            if(progresses[i] < 100){
                progresses[i] = progresses[i] + speeds[i];
            }
            if(progresses[i] > 100){
                progresses[i] = 100;
            }
            
        }
        for(int i=now;i<num;i++){
            if(progresses[i] == 100){
                tmp++;
            }else{
                break;
            }
        }
        if(tmp != 0){
            answer.push_back(tmp);
            now = now + tmp;
        }
    }
    return answer;
}