#include <iostream>
// 대각선에 겹치지 않는 정사각형 개수 구하는 문제
// 최악의 경우 대각선이 모두 걸치지 않을때 
// 확인하지 않아도 되는 경우 구하기 
// 루트 2보다 큰 거리에 있는 경우는 구하지 않아도 될듯 
using namespace std;

long gcd(int a, int b){
    if(b != 0){
        int c = b;
        b = a % b;
        a = c;
        return gcd(a,b);
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    int num = gcd(w,h);
    long x = w / num;
    long y = h / num;
    /*
    long box = 0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(x*i < y*(j+1) && x*(i+1) > y*j){
                box++;
            }
        }
    }*/

    answer = (long long)w * (long long)h;
    //answer = answer - (long long)num * box;
    answer = answer - (long)w - (long)h + num;
    return answer;
}