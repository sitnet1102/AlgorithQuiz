#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int N;
    //vector<int> v;
    int tmp;
    int countingV[10000] = {0};

    // cin, cout 은  scanf, printf 보다 시간이 오래 걸림 
    //cin >> N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        //cin >> tmp;
        scanf("%d", &tmp);
        countingV[tmp-1]++;
    }

    for(int i=0;i<10000;i++){
        //countingV[i] = countingV[i-1]+countingV[i];
        
        for(int j=0;j<countingV[i];j++){
            //v.push_back(i+1);
            printf("%d\n",i+1);
        }
        
    }
    /*
    printf("\n");

    for(int i=0;i<N;i++){
        printf("%d\n",v[i]);
    }
    */

    return 0;
}