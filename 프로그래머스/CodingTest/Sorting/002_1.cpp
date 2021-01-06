// 사전식 정리 
// string 정리는 자동으로 됨 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
bool comp(int a, int b){
    string A, B;
    A = to_string(a);
    B = to_string(b);
    if(A[0] == B[0]){

    }
    return A[0] > B[0];
}
*/
bool comp(string a, string b){
    return a > b;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i=0;i<numbers.size();i++){
        v.push_back(to_string(numbers[i]) + to_string(numbers[i]) + to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), comp);
    //sort(numbers.begin(), numbers.end(), comp);
    /*
    for(int i=0;i<numbers.size();i++){
        cout << numbers[i] << " ";
    }
    cout << "\n";
    */
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
        answer = answer + v[i].substr(0, (v[i].size()/3));
    }
    cout << "\n";
    if(answer[0] == '0'){
        answer = '0';
    }
    return answer;
}

/*
numbers : [0, 5, 10, 15, 20]
return : 52015100

numbers : [1000, 0, 5, 99, 100]
return : 99510010000

numbers : [0, 0, 0, 0, 0]
return : 0

[1, 123, 530, 113, 13, 403, 12]
53040313123121131

*/