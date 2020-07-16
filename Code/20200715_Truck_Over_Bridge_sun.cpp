#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_sum = 0;
    int truck_id = 0;
    int truck_num = truck_weights.size();
    
    queue<int> bridge;
    
    for(int i=0; i<bridge_length; i++)
    {
        bridge.push(0);
    }
    
    while(truck_id < truck_num)
    {
        weight_sum -= bridge.front();
            
        bridge.pop();
        
        if((weight_sum + truck_weights[truck_id]) <= weight)
        {
            bridge.push(truck_weights[truck_id]);
            
            weight_sum += truck_weights[truck_id];
            
            truck_id++;
        }
        else
        {
            bridge.push(0);
        }
        
        answer++;
    }
    
    answer += bridge_length;
        
    return answer;
}
