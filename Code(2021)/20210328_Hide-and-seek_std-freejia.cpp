#include <iostream>
#include <queue>
#define LIMIT 100000
using namespace std;

// 숨바꼭질 BOJ 1697 
 
int n, k; 
queue<int> q;
int visited[LIMIT+1]; // 지점에 도착한 '초'를 저장  

int BFS(){
	
	visited[n] = 1;
	q.push(n);
 	
	while(!q.empty()){
	
		int num = q.front();
		q.pop();

		if(num == k){ // 동생 찾음 
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
 
	cin >> n >> k;

	cout << BFS();
	
	return 0;
}


