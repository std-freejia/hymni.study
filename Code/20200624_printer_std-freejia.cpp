#include <stdio.h>
#include <string>
#include <queue>
#include <utility> // pair
#include <vector>
#include <algorithm>
using namespace std;

// 프린터 (프로그래머스) 
 
/*
1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 
J를 대기목록의 가장 마지막에 넣습니다.
3. 그렇지 않으면 J를 인쇄합니다.
*/

int solution(vector<int> priorities, int location) {

    int answer = 0; // 출력 순서  
	int i = 0;
	
	queue<pair<int,int> > q;
	priority_queue<int, vector<int>, less<int> > pq;
	
	for(i=0; i<priorities.size(); i++){ 
	
		q.push(make_pair(i, priorities[i]));  // 큐 : 인덱스와 우선순위값 pair를 넣는다.  
		pq.push(priorities[i]);  // 우선순위 큐 : 우선순위값만 넣는다.  
	}
	
	while(!q.empty()){
		
		int idx = q.front().first;
		int top_priority = q.front().second;
	
		q.pop();
		
		if(pq.top() == top_priority) {
			
			if(idx == location){ // 타겟 찾음. 종료  
				answer++;
				break; 
				 
			}else{ // 출력 
				pq.pop(); 
				answer++;
			} 
			
		}else { // 맨 뒤로 넣는다  
			q.push(make_pair(idx, top_priority));
		}
		
	} 
    
    return answer;
    
}

