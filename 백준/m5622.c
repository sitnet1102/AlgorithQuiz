#include <stdio.h>

int main() {
    int a;
    int num[10]; // 1 2 3 4 5 6 7 8 9 0
    int alpha[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5,
                     5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 
                     8, 8, 9, 9, 9, 9};
    char ch;
    //char out[15];
    int out = 0;
    int j=0;                    
    for(int i=0;i<10;i++){
        num[i] = i + 2;
    }

    ch = getchar();
    while(ch>64){
        a = ch-65;
        out += num[alpha[a]-1];
        //printf("round : %d, num : %d, ch : %c\n", j, num[alpha[a]-1], ch);
        //out[j] = 48 + alpha[a];
        //printf("round : %d, out : %c\n", j, out[j]);
        j++;
        ch = getchar();
    }

    
    printf("%d\n",out);


    return 0;
}