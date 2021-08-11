// DP 

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    for(int i=3;i<=n;i++){
        p.push_back(p[i-1] + p[i-2]);
    }

    answer = p[n];

    answer = answer % 1234567;
    return answer;
}



/*

1       1 0     1 : (1)
2       0 1     2 : (1, 1), (2)
3       1 1     3 : (1, 1, 1), (2, 1), (1, 2)
5       0 2     4 : (1, 1, 1, 1), (2, 1, 1), (1, 2, 1), (1, 1, 2), (2, 2) 
8       1 2     5 : (1, 1, 1, 1, 1), (2, 1, 1, 1), (1, 2, 1, 1), (1, 1, 2, 1), (1, 1, 1, 2), (2, 2, 1), (2, 1, 2), (1, 2, 2)



*/