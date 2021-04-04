#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 100000
using namespace std;

// 숨바꼭질4  BOJ 13913  

int N, K; // 수빈 위치, 동생 위치 
queue<int> q;
int visited[MAX+1]; // 지점 방문 했을 때의 시간
int from[MAX+1]; // 어디서 왔는지. 
vector<int> track; // 방문 경로  
int now;

void BFS(){

	visited[N] = 0; // 시작 지점 0 초  
	q.push(N);
	
	while(!q.empty()){
	
		now = q.front();
		q.pop();
		
		if(now == K){ // 동생 찾음 			
			break; 
		}
		
		if(now-1 >= 0 && !visited[now-1]){
			visited[now-1] = visited[now] + 1;
			q.push(now-1);
			from[now-1] = now; // 방문순서  
		}
		
		if(now+1 <= MAX && !visited[now+1]){
			visited[now+1] = visited[now] + 1;
			q.push(now+1);
			from[now+1] = now; // 방문순서  
		}	
				
		if(now*2 <= MAX && !visited[now*2]){
			visited[now*2] = visited[now] + 1;
			q.push(now*2);
			from[now*2] = now; // 방문순서    
		}	
	} 

	int idx = now;
	
	// 이전에 방문했던 지점 거슬러 올라간다 
	while(idx != N){ // 시작점이 될 때 까지  
		track.push_back(idx);
		idx = from[idx]; 
	} 
	track.push_back(N); 

	return;
}

int main(void){
 
 	cin >> N >> K;
 
	BFS(); 	 
 
 	printf("%d\n", visited[now]);
 
 	for(int i = track.size()-1; i >= 0 ; i--){
 		printf("%d ", track[i]); 
	}
	
	return 0;
} 