#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool comp(string a, string b){
    return a < b;
}
/*
bool comp(string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }
    return a.size() < b.size();
}
*/

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), comp);
    /*
    for(int i=0;i<phone_book.size();i++){
        cout << phone_book[i] << " ";
    }
    cout << "\n";
    */

    for(int i=1;i<phone_book.size();i++){
        if(phone_book[i-1].size() <= phone_book[i].size()){
            string tmp = phone_book[i].substr(0, phone_book[i-1].size());
            //cout << phone_book[i-1] << " / " << tmp << "\n";
            if(tmp == phone_book[i-1]){
                answer = false;
                break;
            }
        }
    }
    return answer;
}