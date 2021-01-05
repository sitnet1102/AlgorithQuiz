#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
};
struct cmp2 {
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int num = jobs.size();
    int time = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> job;
    priority_queue<vector<int>, vector<vector<int>>, cmp2> ready;
    for(int i=0;i<num;i++){
        job.push(jobs[i]);
    }
    while(!(job.empty() && ready.empty())){
        while(job.top()[0] <= time && !job.empty()){
            vector<int> tmp;
            int a, b;
            a = job.top()[0];
            b = job.top()[1];
            tmp.push_back(a);
            tmp.push_back(b);
            ready.push(tmp);
            job.pop();
        }
        if(!ready.empty()){
            time = time + ready.top()[1];
            answer = answer + time - ready.top()[0];
            ready.pop();
        }else{
            time ++;
        }
        //////
        /*
        cout << "=================================\n";
        cout << "job : " << job.size() << " " << job.top()[0] << " " << job.top()[1] << "\n";
        cout << "ready : " << ready.size() << " " << ready.top()[0] << " " << ready.top()[1]<< "\n";
        cout << "time : " << time << "\n";
        cout << "ans : " << answer << "\n";
        */
    }
    answer = answer / num;
    /*
    for(int i=0;i<num;i++){
        cout << job.top()[0] << " " << job.top()[1] << "\n";
        job.pop();
    }
    */
    return answer;
}