#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n){
        int num = n%3;
        n = n/3;
        if(num == 0){
            answer = "4" + answer;
            n = n - 1;
        }else if(num == 1){
            answer = "1" + answer;
        }else if(num == 2){
            answer = "2" + answer;
        }
    }
    return answer;
}

/*
1   1   1
2   2   2
3   10  4
4   11  11 
5   12  12  
6   20  14
7   21  21
8   22  22  
9   30  24

*/