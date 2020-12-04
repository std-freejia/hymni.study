#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// DFS BFS

int N, M, sV; // 정점, 간선 수 , 시작정점.  
int map[1001][1001]; // 정점리스트  
int check[1001]; // 정점 방문 여부  
queue<int> qu;	  

void DFS(int v){
	
	check[v] = 1; // 방문 표시  
	
	cout << v << ' ';
	
	for(int i = 1; i <= N; i++){
		if(map[v][i] != 0 && check[i] == 0){
			DFS(i); 
		}
	} 

}

void BFS(int v){
	
	qu.push(v);  
	check[v] = 1; // 방문표시  

	while(!qu.empty()){
	
		v = qu.front();
		qu.pop();
		cout << v << ' ';
		
		for(int i = 1; i <= N; i++){  // 주변 탐색  
		 
			if(check[i] == 0 && map[v][i]) { // 첫 방문이면  
			
				check[i] = 1; 
				qu.push(i); 
			} 
		}
	}
}

void input(){
	
	cin >> N >> M >> sV;
 	
 	int a = 0, b = 0;
 	
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1; //  양방향 
	}
} 

int main(void){

 	input(); 
	
 	DFS(sV);
 	cout << '\n';
	memset(check, 0, sizeof(check));
	BFS(sV);
 	
	return 0;
}



