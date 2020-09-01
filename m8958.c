#include <stdio.h>

int main() {
    int n;
    char x[80];
    int score = 0;
    int result = 0;
    int output[1000] = {0,};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",x);
        for(int j=0;j<80;j++){
            
            if(x[j]=='O'){
                score++;                
            }else if(x[j]=='X'){
                score = 0;
            }else{
                score = 0;
                break;
            }           
            result += score;
        }
        output[i] = result;
        result = 0;
    }

    for(int i=0;i<n;i++){
        printf("%d\n",output[i]);
    }



    return 0;
}