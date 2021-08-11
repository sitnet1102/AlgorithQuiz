#include <iostream>
// 대각선에 겹치지 않는 정사각형 개수 구하는 문제
// 최악의 경우 대각선이 모두 걸치지 않을때 
// 확인하지 않아도 되는 경우 구하기 
// 루트 2보다 큰 거리에 있는 경우는 구하지 않아도 될듯 
using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long a, b;
    long num = 0;
    long box = 0;
    long m = 1;
    a = w;
    b = h;
    while(true){
        if(a%2 == 0 && b%2 == 0){
            a = a/2;
            b = b/2;
            num ++;
        }else{
            break;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(b*i < a*(j+1) && b*(i+1) > a*j){
                box++;
            }
        }
    }
    for(int i=0;i<num;i++){
        m = m * 2;
    }

    answer = (long long)w * h - m * box;

    cout << a << " " << b << " " << num << "\n";
    return answer;
}