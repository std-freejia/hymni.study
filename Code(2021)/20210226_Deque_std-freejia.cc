#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <algorithm> 
#include <utility>
using namespace std;


// 덱  

int N, num;
string order;
deque<int> dq;
  
int main(void){

	scanf("%d", &N);
	
	while(N--){
		cin >> order;
		
		if(order == "push_back"){
		
			scanf("%d", &num);
			dq.push_back(num);
			
		}else if(order == "push_front"){
		
			scanf("%d", &num);
			dq.push_front(num);
			
		}else if(order == "front"){
            
			if(!dq.empty()){
				printf("%d\n", dq.front());
			}else{
				printf("%d\n", -1);
			}
		}else if(order == "back"){
            
			if(!dq.empty()){
				printf("%d\n", dq.back());
			}else{
				printf("%d\n", -1);
			}
			
		}else if(order == "size"){
			
			printf("%d\n", dq.size());
			
		}else if(order == "empty"){
			
			num = (dq.empty()) ? 1:0;
			printf("%d\n", num);
			
		}else if(order == "pop_front"){
		
			if(!dq.empty()){
				printf("%d\n", dq.front());	
				dq.pop_front();
			}else{
				printf("%d\n", -1);
			}
	
		}else if(order == "pop_back"){
		
			if(!dq.empty()){
				printf("%d\n", dq.back());	
				dq.pop_back();
			}else{
				printf("%d\n", -1);
			}
		}
	}
		
	return 0;
} 