#include <stdio.h>
#include <string.h>

int main () {
    int n, num, a, b;
    char word[102];
    
    int answer = 0;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        int alpha[26] = {0,};
        scanf("%s",word);
        //printf("\n");
        num = strlen(word);
        for(int j=0;j<num;j++){
            /*
            ///////////
            printf("alpha  %d : ", j);
            for(int k=0;k<26;k++){
                printf("%d ",alpha[k]);
            }
            printf("\n");
            ///////////
            */
            //printf("%d ",word[j]);
            a = word[j] - 97;
            
            alpha[a]++;
            if(j == 0){

            }else if(j == num-1){
                b = word[j-1] - 97;
                if(alpha[a] > 200){
                    goto Loop1;
                }else if(alpha[b]>200){
                    goto Loop1;
                }
            }else if(word[j] != word[j-1]){
                b = word[j-1] - 97;
                if(alpha[b] > 200){
                    goto Loop1;
                }
                alpha[b] += 300;
            }

        }

        Loop2:
        //printf("\n\n%s", word);
        answer ++; 


        Loop1:
        ;
        

        //printf("\n");
    }

    printf("%d\n",answer);

    return 0;
}