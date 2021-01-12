#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;
vector<tuple <string, int, int>> v;
bool comp(tuple <string, int, int> a, tuple <string, int, int> b){
    if(get<0>(a) == get<0>(b)){
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}
bool comp2(tuple<string, int, int, int> a, tuple<string, int, int, int> b){
    return get<1>(a) > get<1>(b);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector <tuple <string, int, int, int>> best;    // 장르, 재생회수 합, 가장 많이, 두번째 많이    // 두번째 없으면 -1
    int cnt = 0;
    int sum = 0;
    for(int i=0;i<plays.size();i++){
        string tmp_s = genres[i];
        int tmp_n = plays[i];
        tuple<string, int, int> tmp;
        tmp = make_tuple(tmp_s, tmp_n, i);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), comp);
    /*
    for(int i=0;i<v.size();i++){
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << "\n";
    }
    cout << "\n";
    */
    for(int i=0;i<v.size();i++){
        cnt ++;
        sum = sum + get<1>(v[i]);
        if(i == v.size() -1){
            tuple <string, int, int, int> tmp_tuple;
            int first_num = get<2>(v[i]);
            int second_num = -1;
            if(i==0 || get<0>(v[i-1]) != get<0>(v[i])){
                // 장르에 노래가 1개 일때 

            }else if(get<0>(v[i-1]) == get<0>(v[i])){
                // 장르에 노래가 2개 이상 
                second_num = get<2>(v[i-1]);
                if(get<1>(v[i]) == get<1>(v[i-1])){
                    if(first_num > second_num){
                        int x = first_num;
                        first_num = second_num;
                        second_num = x;
                    }
                }
            }
            tmp_tuple = make_tuple(get<0>(v[i]), sum, first_num, second_num);
            best.push_back(tmp_tuple);
        }else{
            if(get<0>(v[i]) != get<0>(v[i+1])){
                tuple <string, int, int, int> tmp_tuple;
                int first_num = get<2>(v[i]);
                int second_num = -1;
                if(i==0 || get<0>(v[i-1]) != get<0>(v[i])){
                    // 장르에 노래가 1개 일때 

                }else if(get<0>(v[i-1]) == get<0>(v[i])){
                    // 장르에 노래가 2개 이상 
                    second_num = get<2>(v[i-1]);
                    if(get<1>(v[i]) == get<1>(v[i-1])){
                        if(first_num > second_num){
                            int x = first_num;
                            first_num = second_num;
                            second_num = x;
                        }
                    }
                }

                tmp_tuple = make_tuple(get<0>(v[i]), sum, first_num, second_num);
                best.push_back(tmp_tuple);
                sum = 0;
            }
        }
    }
    sort(best.begin(), best.end(), comp2);
    //cout << "==================================================\n";
    for(int i=0;i<best.size();i++){
        //cout << get<0>(best[i]) << " " << get<1>(best[i]) << " " << get<2>(best[i]) << " " << get<3>(best[i]) <<"\n";
        answer.push_back(get<2>(best[i]));
        if(get<3>(best[i]) != -1){
            answer.push_back(get<3>(best[i]));
        }
    }
    

    return answer;
}

/*
genres=["classic","classic","classic","classic","pop"]
plays=[500,150,800,800,2500]
*/