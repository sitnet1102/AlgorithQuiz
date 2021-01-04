#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
vector<tuple <string, int, int>> v;
bool comp(tuple <string, int, int> a, tuple <string, int, int> b){
    if(get<0>(a) == get<0>(b)){
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<plays.size();i++){
        string tmp_s = genres[i];
        int tmp_n = plays[i];
        tuple<string, int, int> tmp;
        make_tuple(tmp_s, tmp_n, i);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0;i<v.size();i++){
        if(i == v.size() -1){

        }else{
            if(get<0>(v[i]) != get<0>(v[i+1])){
                
            }
        }
    }
    
    return answer;
}