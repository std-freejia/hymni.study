#include <iostream> 
#include <vector>
#include <queue>
#include <cstring> // memset()
#include <algorithm>
#define MAX_SIZE 20000+1
#define RED 1
#define BLUE 2
using namespace std;

// 이분그래프  (BOJ 1707)

int K, V, E; // 정점, 간선 개수  
vector<int> G[MAX_SIZE]; 
int check[MAX_SIZE]; // 미방문 0, RED 1, BLUE 2 

void BFS(int start){

	queue<int> q;
	int color = RED;
	
	check[start] = color;
	q.push(start);
	
	while(!q.empty()){
	
		int now = q.front(); // 현재 색깔  
		q.pop();
		
		if(check[now] == RED){ // 현재 색깔과 다르게 바꾼다.  
			color = BLUE;
		}else{
			color = RED;
		}
		
		int adj_size = G[now].size(); 

		for(int i = 0; i < adj_size; i++){
			int next = G[now][i];
			
			if(!check[next]){
				check[next] = color; // 색깔 칠하고 큐에 넣는다  
				q.push(next);
			}
		}
	}	
} 

bool is_bipartite(){
	
	for(int i = 1; i <= V; i++){ // 모든 정점의 '인접 정점들'을 확인하자  
		
		int size = G[i].size();
		
		for(int j = 0; j <size; j++){ // i 정점의 인접 정점 모두 확인  
			int next = G[i][j];
			if(check[next] == check[i]){
				return false;
			}	
		}
	}
	
	return true;
}
 
void input(){
 
	cin >> K; // 테스트 케이스 개수  
	
	while(K--){
		cin >> V >> E; // 정점 개수, 간선 개수 
	
		int a=0, b=0;	

		for(int i = 0 ; i< E; i++){ // 연결리스트 만들기  
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		for(int i = 1; i <= V; i++){ // BFS로 탐색  
 			if(!check[i]) {
 				BFS(i);
			 }
		}
 
		string answer = (is_bipartite()) ? "YES" : "NO"; 
 		cout << answer << '\n';
 		
 		memset(check, 0, sizeof(check)); // 방문 배열 초기화 
 		for(int i = 0; i <= V; i++){ // 벡터 원소 0 초기화  
 			G[i].clear();
		}
	}
}

int main() {	

 	input();

	return 0;
} 
