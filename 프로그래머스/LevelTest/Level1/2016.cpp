#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector <string> d = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int day = 0;
    for(int i=1;i<a;i++){
        if(i==2){
            day = day + 29;
        }else if(i==4 || i==6 || i==9 || i == 11){
            day = day + 30;
        }else{
            day = day + 31;
        }
    }
    day = day + b;
    day = day % 7;
    answer = d[day];
    return answer;
}