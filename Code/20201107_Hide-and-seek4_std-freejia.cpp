#include <iostream> 
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 100000
using namespace std;

// 숨바꼭질4  (BOJ 13913) 

int N, K; // 수빈위치 , 동생위치  

int from[MAX+1];  // 어디서 왔는지  
int time[MAX+1]; // 방문했을 때 시간  

void BFS(){
	
	queue<int> q;
	
	q.push(N);
	time[N] = 0; // 시작지점  
	
	while(!q.empty()){
	
		int now = q.front(); // 현재 지점  
		q.pop();
		
		if(now == K) { // 동생 찾았다 
			break; 
		} 
		
		if(now - 1 >= 0 && time[now-1] == 0){
			from[now-1] = now;
			q.push(now-1);
			time[now-1] = time[now] + 1; // 1초 더 흘렀다.  
		}
		
		if(now + 1 <= MAX && time[now+1] == 0){
			from[now+1] = now;
			q.push(now+1);
			time[now+1] = time[now] + 1; // 1초 더 흘렀다.  
		}
		
				
		if(now * 2 <= MAX && time[now*2] == 0){
			from[now*2] = now;
			q.push(now*2);
			time[now*2] = time[now] + 1; // 1초 더 흘렀다.  
		}
	
	}
}

void out(){ // 경로 스택 출력  

	// 빠른 시간 출력 
	cout << time[K] << '\n'; 

 	stack<int> path;
 	
 	int index = K; //도착지점에서 시작해서 시작지점N 까지 거슬러 올라간다.  
 	path.push(K);
 	
	while(index != N){ 
		path.push(from[index]);
		index = from[index];
	} 	

	while(!path.empty()){
		cout << path.top() << ' ';
		path.pop();
	}
 	
}
 
void input(){

	cin >> N >> K; // 수빈 위치, 목적 위치 
}

int main() {	

 	input();
	BFS();
	out(); // 경로 출력  

	return 0;
} 
