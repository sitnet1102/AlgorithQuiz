#include <stdio.h>

int main() {
    long int arr[26] ={0,};
    char input;
    int num;
    int max = 0;
    int maxindex;
    int a = 0;
    char output;
    //int check = 0;
    input = getchar();
    while(input > 64){
        //printf("roudn : %d, input : %c\n", check, input);
        //check ++;
        num = input - 65;
        if(num > 25){
            num = num - 32;
        }
        arr[num]++;
        input = getchar();
    }

    for(int i=0;i<26;i++){
        if(arr[i] > max){
            max = arr[i];
            maxindex = i;
        }
    }


    for(int i=0;i<26;i++){
        if(arr[i] == max){
            a++;
        }
    }
    if(a == 1){
        output = maxindex + 65;
    }else{
        output = 63;
    }
    printf("%c\n",output);


    return 0;
}