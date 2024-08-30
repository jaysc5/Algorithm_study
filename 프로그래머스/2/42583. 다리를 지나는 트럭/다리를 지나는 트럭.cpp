#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> wait;
    queue<int> bridge;
    int bridge_weights = 0;
    
    for (int truck : truck_weights) wait.push(truck);
    for (int i=0; i<bridge_length; i++) bridge.push(0);
    
    while (wait.size()!=0 or bridge_weights > 0){
        int out_truck = bridge.front();
        bridge.pop();
        bridge_weights -= out_truck;
        
        if (wait.size()!=0 and bridge_weights + wait.front() <= weight){
            int new_truck = wait.front();
            wait.pop();
            bridge_weights += new_truck;
            bridge.push(new_truck);
        }
        else
            bridge.push(0);
        
        answer++;
    }
    
    return answer;
}