#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int i=0;
    int num=0;
    int len;
    //char ch[3];
    scanf("%s",input);
    len = strlen(input);

    while(input[i] != '\0'){
        if(len - i < 1){
            goto Loop1;
        }
        if(input[i] == 'c'){
            if(input[i+1] == '=' || input[i+1] == '-'){
                i += 2;
                goto Loop;
            }
        }

        if(input[i] == 'd'){
            if(len - i < 2){
                goto Loop1;
            }
            if(input[i+1] == '-'){
                i += 2;
                goto Loop;
            }else if(input[i+1] == 'z' && input[i+2] == '='){
                i += 3;
                goto Loop;
            }            
        }

        if(input[i] == 'l'){
            if(input[i+1] == 'j'){
                i += 2;
                goto Loop;
            }
        }

        if(input[i] == 'n'){
            if(input[i+1] == 'j'){
                i += 2;
                goto Loop;
            }
        }

        if(input[i] == 's'){
            if(input[i+1] == '='){
                i += 2;
                goto Loop;
            }
        }

        if(input[i] == 'z'){
            if(input[i+1] == '='){
                i += 2;
                goto Loop;
            }
        }
        Loop1:
        i++;
        Loop:
        num ++;
    }

    printf("%d\n", num);

    return 0;
}