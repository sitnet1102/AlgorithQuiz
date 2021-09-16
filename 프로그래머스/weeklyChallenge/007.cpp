#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer;
    vector<int> room;
    vector<vector<int>> meet;
    int lNum = 0;
    for(int i=0;i<enter.size();i++){
        vector<int> tmp;
        for(int j=0;j<enter.size();j++){
            tmp.push_back(0);
        }
        meet.push_back(tmp);
    }
    
    for(int i=0;i<enter.size();i++){
        room.push_back(enter[i]);
        /*
        for(int j=0;j<room.size();j++){
            cout << room[j] << " ";
        }
        cout << "  -- " << lNum;
        cout << "\n";
        */
        for(int j=0;j<room.size();j++){
            for(int k=0;k<room.size();k++){
                if(!meet[room[j]-1][room[k]-1]){
                    meet[room[j]-1][room[k]-1] = 1;
                }
            }
        }
        /*
        나갈 수 있는 사람 확인 
        */
        for(int j=lNum;j<leave.size();j++){
            bool check = true;
            for(int k=0;k<room.size();k++){
                if(leave[j] == room[k]){
                    room.erase(room.begin()+k);
                    check = false;
                    break;
                }
            }
            if(check){
                lNum = j;
                break;
            }
        }
    }
    /*
    for(int i=0;i<meet.size();i++){
        for(int j=0;j<meet[i].size();j++){
            cout << meet[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for(int i=0;i<meet.size();i++){
        int num=0;
        for(int j=0;j<meet[i].size();j++){
            if(i!=j&&meet[i][j]==1){
                num++;
            }
        }
        answer.push_back(num);
    }
    
    return answer;
}