#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    vector<int> prim;
    vector<int> n_num;
    vector<int> m_num;
    vector<int> gcd;
    vector<int> lcd;
    int gcd_num = 1;
    int lcd_num = 1;
    if(n>m){
        int tmp = n;
        n = m;
        m = tmp;
    }
    if(m%n == 0){
        answer.push_back(n);
        answer.push_back(m);
        return answer;
    }

    for(int i=2;i<=m;i++){
        bool check = true;
        for(int j=0;j<prim.size();j++){
            if(i%prim[j] == 0){
                check = false;
                break;
            }
        }
        if(check){
            prim.push_back(i);
        }
    }
    for(int i=0;i<prim.size();i++){
        n_num.push_back(0);
        m_num.push_back(0);
        //cout << prim[i] << " ";
    }
    //cout << "\n";

    while(n != 1){
        for(int i=0;i<prim.size();i++){
            if(n%prim[i] == 0){
                n_num[i] ++;
                n = n / prim[i];
                break;
            }
        }
    }
    while(m != 1){
        for(int i=0;i<prim.size();i++){
            if(m%prim[i] == 0){
                m_num[i] ++;
                m = m / prim[i];
                break;
            }
        }
    }

    for(int i=0;i<prim.size();i++){
        if(n_num[i] < m_num[i]){
            gcd.push_back(m_num[i]);
            lcd.push_back(n_num[i]);
        }else{
            gcd.push_back(n_num[i]);
            lcd.push_back(m_num[i]);
        }
    }
    for(int i=0;i<prim.size();i++){
        for(int j=0;j<gcd[i];j++){
            gcd_num = gcd_num * prim[i];
        }
        for(int j=0;j<lcd[i];j++){
            lcd_num = lcd_num * prim[i];
        }
    }

    answer.push_back(lcd_num);
    answer.push_back(gcd_num);
    return answer;
}