#include <stdio.h>
#include <string.h>

int main() {
    int T, R, num;
    char ch[20];
    
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %s", &R, ch);
        num = strlen(ch);
        for(int j=0;j<num;j++){
            for(int k=0;k<R;k++){
                printf("%c",ch[j]);
            }
        }
        printf("\n");
    }
    return 0;
}