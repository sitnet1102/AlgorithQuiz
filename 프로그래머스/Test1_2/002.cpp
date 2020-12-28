#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int loca = 0;
    int before_score = 0;
    int score = 0;
    for(int i=0;i<3;i++){
        char tmp = dartResult[loca];
        int num = atoi(&tmp);
        char bonus = dartResult.at(loca+1);
        if(bonus == '0'){
            num = 10;
            loca ++;
            bonus = dartResult.at(loca+1);
        }
        if(bonus == 'S'){
            score = num;
        }else if(bonus == 'D'){
            score = num * num;
        }else{
            score = num * num * num;
        }
        if(dartResult.size() > loca + 2){
            if(dartResult.at(loca+2) == '#'){
                score = (-1) * score;
                loca ++;
            }else if(dartResult.at(loca+2) == '*'){
                score = 2 * score + before_score;
                loca ++;
            }
        }
        answer = answer + score;
        before_score = score;
        loca = loca + 2;
    }
    
    
    return answer;
}