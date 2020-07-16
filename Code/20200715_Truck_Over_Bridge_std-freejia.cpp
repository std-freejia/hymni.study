#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 다리를 지나는 트럭   (프로그래머스 std-freejia) 

int solution(int bridge_length, int weight, vector<int> truck_weights) {

	// 시간
	int answer = 0;
	
	// 도로 위 차 
	queue<int> count;
	
	// 차마다 가야할 남은 거리 (도로를 얼마나 더 가야 하는지)  
	queue<int> bridge_on;
	
	// 도로 위의 차 무게 합계
	int current_weight = 0;
	
	int i = 0;
	
	while(true){
	
		//차들이 가야할 거리 
		int togo_size = bridge_on.size();
		
		// 차를 도로에 진입시킨다.  
		for(i = 0; i < togo_size; i++){
		
			// 제일 앞에 가고있는 차의 남은 거리  
			int len_front = bridge_on.front();
			
			bridge_on.pop();
			
			if(len_front <= 1){ // 남은 거리가 1 이하라면, 이 차의 무게를 제외시킨다 
				current_weight -= count.front();
				count.pop();
				continue;
			} else{
				//  거리 감소시키고 다시 push  
				bridge_on.push(--len_front); 
			}
		} 
		
		// 도로의 제한무게 만큼 차를 집어넣는다. 대기 차량이 1개 이상 있어야 함.  
		if(truck_weights.at(0) + current_weight <= weight && truck_weights.size() > 0 ) {
			
			count.push(truck_weights.at(0)); // 도로에 차 추가
						
			current_weight += truck_weights.at(0); // 현재 도로 무게에 차 무게 추가  
			
			truck_weights.erase(truck_weights.begin());  // 대기 차량 삭제  
			
			bridge_on.push(bridge_length); // 이 차가 지나야할 도로 거리 추가  
			
			
		}
		
		answer++; // 시간이 지나감 
		
		if(count.size() == 0 && truck_weights.size() == 0){
			break;
		} 
	
	}
	 
    return answer;
}
