#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int num = participant.size();
    bool check = true;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<num-1;i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            check = false;
            break;
        }
    }
    /*
    cout << "p = ";
    for(int i=0;i<num;i++){
        cout << participant[i] << " ";
    }
    cout << "\n";
    cout << "c = ";
    for(int i=0;i<num-1;i++){
        cout << completion[i] << " ";
    }
    cout << "\n";
    */
    /*
    for(int i=0;i<num;i++){
        for(int j=0;j<completion.size();j++){
            if(participant[0] == completion[j]){
                participant.erase(participant.begin());
                completion.erase(completion.begin() + j);
                break;
            }
        }
    }
    */
   if(check){
       answer = participant[num-1];
   }
    //answer = participant[0];
    return answer;
}