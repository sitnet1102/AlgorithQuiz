#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(int i=0;i<scores.size();i++){
        int max = -1;
        int min = 101;
        int max_check = 0;
        int min_check = 0;
        int sum = 0;
        int num = scores.size();
        float average = 0;
        string grade = "";
        for(int j=0;j<scores.size();j++){
            if(scores[j][i] > max){
                max = scores[j][i];
                max_check = 0;
            }else if(scores[j][i] == max){
                max_check ++;
            }
            if(scores[j][i] < min){
                min = scores[j][i];
                min_check = 0;
            }else if(scores[j][i] == min){
                min_check ++;
            }
            sum = sum + scores[j][i];
        }
        if(max == scores[i][i] &&  max_check == 0){
            sum = sum - max;
            num --;
        }else if(min == scores[i][i] && min_check == 0){
            sum = sum - min;
            num --;
        }
        average = (float)sum / (float)num;
        /*
        cout << "max : " << max << ", " << max_check << "\n";
        cout << "min : " << min << ", " << min_check << "\n";
        cout << "sum : " << sum << ", " << average << "\n";
        cout << "\n";
        */
        if(average >= 90){
            grade = "A";
        }else if(average >= 80){
            grade = "B";
        }else if(average >= 70){
            grade = "C";
        }else if(average >= 50){
            grade = "D";
        }else{
            grade = "F";
        }
        answer = answer + grade;
    }
    return answer;
}