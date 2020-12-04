#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Person{
    int num;
    int age;
    char name[100];
}typedef p;

int main(){
    int N;
    vector<p> v;

    scanf("%d", &N);

    for(int i=0;i<N;i++){
        p tmp;
        char tmp_name[101];
        //int age;
        //string name;
        //scanf("%d %s", &age, &name);
        tmp.num = i;
        //cin >> tmp.age >> tmp.name;
        scanf("%d %s", &tmp.age, &tmp_name);
        tmp.name = tmp_name;
        v.push_back(tmp);
    }
    printf("\n");
    for(int i=0;i<N;i++){
        printf("%d %s\n", v[i].age, v[i].name);
    }

    return 0;
}