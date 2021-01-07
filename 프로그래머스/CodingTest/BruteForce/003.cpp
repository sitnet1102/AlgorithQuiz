#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;
    int A, B ;          // A = xy -> y-b ,  B = x + y  -> 2 + b/2   
    // x 가로 , y 세로 
    // x >= y
    A = yellow + brown;     // A = xy -> y + b
    B = 2 + brown/2;        // B = x + y  -> 2 + b/2
    
    //cout << A << " " << B;

    for(int i=3;i < brown/2;i++){
        if(i * (B-i) == A ){
            answer.push_back(B-i);
            answer.push_back(i);
            break;
        }
    }



    return answer;
}