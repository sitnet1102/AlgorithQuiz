#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;                         // 지난 시간
    int weight_on_bridge = 0;               // 다리 위에 있는 트럭의 무게 합 
    int waiting_truck = 0;                  // 대기 트럭 가장 앞 번호 인덱스
    int on_bridge_truck = 0;                // 다리 위에 있는 트럭 중 가장 앞 
    vector<int> location;                   // 트럭 별 위치 
    /*
    queue<int> before_bridge;
    queue<int> on_bridge;
    queue<int> out_bridge;
    */

    for(int i=0;i<truck_weights.size();i++){
        //before_bridge.push(truck_weights[i]);
        location.push_back(0);
    }

    /*
    for(int i=0;i<truck_weights.size();i++){
        cout << location[i] << " ";
    }
    cout << "\n";

    while(before_bridge.empty() && on_bridge.empty()){
        answer++;
        // 

    }
    */
   while(location[truck_weights.size()-1] <= bridge_length ){   //waiting_truck != (truck_weights.size()-1) && 
        /*
        // 다리 위에 트럭이 올라갈 때 처리 
        
        if(location[waiting_truck] > bridge_length){
            waiting_truck ++;
        }
        // 다리 위에 있는 트럭 무게 확인 후 처리 

        // 시간 추가

        // 다리 위에 있는 트럭 처리 
        */

        answer ++;
        // 다리 위에 있는 트럭 처리
        for(int i=on_bridge_truck;i<waiting_truck;i++){
            location[i] = location[i] + 1;
        }
        // 다리를 지날 때 
        if(location[on_bridge_truck] > bridge_length){
            weight_on_bridge = weight_on_bridge - truck_weights[on_bridge_truck];
            on_bridge_truck ++;
        }
        // 다리에 올라갈 때
        if(weight_on_bridge + truck_weights[waiting_truck] <= weight && waiting_truck - on_bridge_truck <= bridge_length){
            if(waiting_truck != truck_weights.size()){
                weight_on_bridge = weight_on_bridge + truck_weights[waiting_truck];
                location[waiting_truck] = location[waiting_truck] + 1;
                waiting_truck ++;
            }
        }
        
        cout << "=====================================\n";
        cout << "time : " << answer << "\nout :";
        for(int a=0;a<on_bridge_truck;a++){
            cout << truck_weights[a] << " ";
        }
        cout << "\non : ";
        for(int a=on_bridge_truck;a<waiting_truck;a++){
            cout << truck_weights[a] << " ";
        }
        cout << "\nwait : ";
        for(int a=waiting_truck;a<truck_weights.size();a++){
            cout << truck_weights[a] << " ";
        }
        cout << "\n-------------------------------------\n";
        cout << weight_on_bridge << "\n";
        for(int a=0;a<truck_weights.size();a++){
            cout << location[a] << " ";
        }
        cout << "\n" << endl;
        
    }
   
    return answer;
}

int main (){
    int bridge_length;
    int weight;
    vector<int> truck_weight;
    int n;
    int ret;
    cin >> n;
    cin >> bridge_length;
    cin >> weight;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        truck_weight.push_back(tmp); 
    }
    ret = solution(bridge_length, weight, truck_weight);
    cout << ret << "\n";
    

    return 0;
}