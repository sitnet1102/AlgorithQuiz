#include <stdio.h>

int main() {
    int num = 1;
    int a=0;
    char input;
    input = getchar();
    if(input == 32){
        num --;
        a=1;
    }
    while(input>31){
        a=0;
        if(input == 32){
            num++;
            a=1;
        }
        input = getchar();
    }
    if(a == 1){
        num--;
    }
    printf("%d\n",num);


    return 0;
}