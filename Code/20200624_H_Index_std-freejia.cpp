#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// H-index (프로그래머스) by std-freejia 


int solution(vector<int> citations){
	
	int answer = 0;
	
	// 정렬 
	sort(citations.begin(), citations.end(), greater<int>()); 
		
	while(answer < citations.size()){
		
		if(citations[answer] <= answer){ // 인덱스 보다 작아지는 순간 종료. 
			break;
		}else{
			answer++;
		}
	}

	return answer;
}
