#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// DFS BFS

int N, M; // 정점, 간선 수  
int map[1001][1001]; // 정점리스트  
int check[1001]; // 정점 방문 여부  
queue<int> qu;	  

void DFS(int v){
	
	check[v] = 1; // 방문 
	
	cout << v << ' ';
	
	for(int i = 1; i <= N; i++){
		if(map[v][i] != 0 && check[i] == 0){
			DFS(i); 
		}
	} 

}

void BFS(int v){
	
	qu.push(v); // 첫 정점 방문  
	check[v] = 1; 

	while(!qu.empty()){
	
		//전단의 데이터
		v = qu.front();
		qu.pop();
		cout << v << ' ';
		
		for(int i = 1; i <= N; i++){ // v 정점과 연결된 노드를 찾는다.  
		 
			if(check[i] == 0 && map[v][i]) { // 첫 방문이라면, 
			
				check[i] = 1; // 방문표시 
				qu.push(i); // 큐에 푸시 
			} 
		}
	}
}

int main(void){

	//freopen("input.txt", "rt", stdin);
	
	int startV = 0, a = 0, b = 0, v = 0;
	
	cin >> N >> M >> startV;
 	
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1; // 간선은 양방향 
	}
	

 	DFS(startV);
 	cout << '\n';
	
	memset(check, 0, sizeof(check)); // 방문 체크 배열 0으로 초기화  
	BFS(startV);
 
	
	return 0;
}



