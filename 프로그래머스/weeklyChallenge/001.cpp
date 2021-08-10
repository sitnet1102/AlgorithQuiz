#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    int answer = 0;
    int sum = 0;
    for(int i=1;i<=count;i++){
        sum = sum + i*price;
    }
    if(money < sum){
        answer = sum - money;
    }
    return answer;
}