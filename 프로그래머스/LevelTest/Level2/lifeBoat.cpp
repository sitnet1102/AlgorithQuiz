#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size()-1;
    sort(people.begin(),people.end());

    for(int i=0;i<=n;i++){
        while(i<n && people[i] + people[n--] > limit){
            answer++;
        }
        answer ++;
    }
    return answer;
}