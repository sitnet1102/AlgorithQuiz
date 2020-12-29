#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Person{
    int num;
    int age;
    string name;
}typedef p;

bool compare(p a, p b){
    if(a.age == b.age){
        return a.num < b.num;
    }
    return a.age < b.age;
}

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
        cin >> tmp.age;
        cin >> tmp_name;
        //scanf("%d %s", &tmp.age, tmp_name);
        tmp.name = tmp_name;
        //printf("%s\n", tmp_name);
        v.push_back(tmp);
    }
    //printf("\n");
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<N;i++){
        //printf("%d %s\n", v[i].age, v[i].name);
        cout << v[i].age << " " << v[i].name << "\n";
    }

    return 0;
}