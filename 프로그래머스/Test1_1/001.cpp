/*
〈 돌아가기 스킬 체크 테스트 Level.1C++ 레퍼런스 도움말 컴파일 옵션 테스트 종료
문제1
0 / (50.0)
 
문제2
0 / (50.0)
문제 설명
2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 요일의 이름은 일요일부터 토요일까지 각각 SUN,MON,TUE,WED,THU,FRI,SAT

입니다. 예를 들어 a=5, b=24라면 5월 24일은 화요일이므로 문자열 TUE를 반환하세요.

제한 조건
2016년은 윤년입니다.
2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다)
입출력 예
a	b	result
5	24	TUE
solution.cpp
1
#include <string>
2
#include <vector>
3
​
4
using namespace std;
5
​
6
string solution(int a, int b) {
7
    string answer = "";
8
    return answer;
9
}
실행 결과
실행 결과가 여기에 표시됩니다.
종료까지
00:39:03
*/

// 5월 24일 기대값 TUE

#include <string>
#include <vector>
#include <iostream>

using namespace std;
// (1, 1) -> FRI
// 1, 3, 5, 7, 8, 10, 12    -> 31
// 2                        -> 29
// 4, 6, 9, 11              -> 30
string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    string answer = "";
    int num = -1;
    for(int i=1;i<a;i++){
        //cout << "num = " << num << "\n";
        switch (i)
        {
        case 2 :
            num = num + 29;
            break;
        case 4 : 
        case 6 :
        case 9 :
        case 11 :
            num = num + 30;
            break;        
        default:
            num = num + 31;
            break;
        }
        /*
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
            num = num + 31;
        }else if(i == 2){
            num = num + 29;
        }else if(i == 4 || i == 6 || i == 9 || i == 11){
            num = num + 30;
        }
        */
    }
    num = num + b;
    //cout << num;
    num = num % 7;
    answer = day[num];
    return answer;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << solution(a, b);
    return 0;
}