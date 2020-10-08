#include <iostream>
#include <queue>
#include <algorithm> 
#define MAX 100000
#define INF 987654321
using namespace std;

// 숨바꼭질3   지아  
 
int N, K;
queue<int> q;
int visit[MAX + 1];  	// i위치에서 최소의 시간을 저장하는 visit배열

int BFS(){

	q.push(N);
	visit[N] = 0; // N지점에서 시작할 때 시간은 0초. 
	
	while(!q.empty()){
	
		int X = q.front(); // 현재 지점  
		q.pop();
		
		if(X == K) { // 동생에게 도착 
			return visit[X]; // X지점에 도달한 시간을 리턴  
		}
		
		for(int nextX : {X*2, X-1, X+1}){
		
			if(nextX < 0 || nextX > MAX) continue; // 인덱스 초과는 안간다. 
			
			if(visit[nextX] > visit[X]+1){ // 가본다 
				if(2*X == nextX) visit[nextX] = visit[X];
				else visit[nextX] = visit[X]+1; 
				q.push(nextX); 
			}
		}
		
	}
}

int main(void){
 
 	//freopen("input.txt", "rt", stdin);
 	
 	scanf("%d %d", &N, &K);
 	
 	for(int i = 0; i <= MAX; i++){ // 큰 수로 초기화 해둔다 
 		visit[i] = INF; 
	}

	int answer = BFS(); 
	
	cout << answer;
 
	return 0;
} 


