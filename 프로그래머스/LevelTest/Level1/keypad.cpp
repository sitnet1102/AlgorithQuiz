#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int key[4][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {-1,0,-1}
    };
    int left[2] = {3,0};
    int right[2] = {3,2};

    for(int i=0;i<numbers.size();i++){
        bool check = true;      // true 일 때, left      false 일 때, right 
        int num_loca[2];
        char ans;
        for(int x=0;x<4;x++){
            for(int y=0;y<3;y++){
                if(key[x][y] == numbers[i]){
                    num_loca[0] = x;
                    num_loca[1] = y;
                }
            }
        }
        if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0){
            int l_num = abs(num_loca[0] - left[0]) + abs(num_loca[1] - left[1]);
            int r_num = abs(num_loca[0] - right[0]) + abs(num_loca[1] - right[1]);
            if(l_num > r_num){
                check = false;
            }
            if(l_num == r_num){
                if(hand == "right"){
                    check = false;
                }
            }
        }else if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            check = true;
        }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            check = false;
        }
        if(check){
            left[0] = num_loca[0];
            left[1] = num_loca[1];
            ans = 'L';
        }else if(!check){
            right[0] = num_loca[0];
            right[1] = num_loca[1];
            ans = 'R';
        }

        /////////////////////////////
        //cout << key[left[0]][left[1]] << "  " << key[right[0]][right[1]] << "\n";

        /////////////////////////////

        answer = answer + ans;
    }

    return answer;
}