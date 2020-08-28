#include <iostream>
#include <queue>
#define LIMIT 100000
using namespace std;

// 숨바꼭질 
 
int N, K; 
queue<int> q;
int visited[LIMIT+1]; // 지점에 도착했을 때의 '초'를 저장  

int BFS(int n){
	
	visited[n] = 1;
	q.push(n);
 	
	while(!q.empty()){
	
		int num = q.front();
		q.pop();

		if(num == K){ // 동생 찾음 
			//cout << visited[num]-1;
			//break;
			return visited[num]-1;
		}
		
		if(num + 1 <= LIMIT && !visited[num+1]){
			
			q.push(num+1);
			visited[num+1] = visited[num]+1;
		}
		
		if(num * 2 <= LIMIT && !visited[num*2]){
			
			q.push(num * 2);
			visited[num * 2] = visited[num]+1;
		}
		
		if(num-1 >= 0 && !visited[num-1]){
			
			q.push(num-1);
			visited[num-1] = visited[num]+1;
		}		
	}
}
 
int main(void){
 
	cin >> N >> K;

	cout << BFS(N);
	
	return 0;
}



