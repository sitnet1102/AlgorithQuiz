#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<arr1.size();i++){
        vector<int> a1;
        vector<int> a2;
        int num1 = arr1[i];
        int num2 = arr2[i];
        string str = "";
        for(int j=0;j<n;j++){
            int tmp = num1%2;
            num1 = num1/2;
            a1.insert(a1.begin(),tmp);
            tmp = num2%2;
            num2 = num2/2;
            a2.insert(a2.begin(),tmp);
        }
        /*
        cout << "===============================\n";
        for(int j=0;j<a1.size();j++){
            cout << a1[j] << " ";
        }
        cout << "        ";
        for(int j=0;j<a2.size();j++){
            cout << a2[j] << " ";
        }
        cout << "\n";
        */
       
        for(int j=0;j<a1.size();j++){
            if(a1[j] == 0 && a2[j] == 0){
                str = str + " ";
            }else{
                str = str + "#";
            }
        }
        answer.push_back(str);
    }

    return answer;
}