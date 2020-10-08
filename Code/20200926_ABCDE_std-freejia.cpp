#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstring>
using namespace std;
 
// ABCDE (BOJ 13023번) 지아  
 
vector<int> map[2001];
int check[2001];
int N, M, a, b;
int answer;

void DFS(int start, int depth){
	
	if(depth == 4){
		answer = 1; 
		return;
	}
	
	check[start] = 1; // 현재 노드 방문  
	
	for(int i = 0; i < map[start].size(); i++){
		
		int next = map[start][i]; // 다음 방문할 노드 
		 
		if(!check[next]){
			check[next] = 1;
			DFS(next, depth+1);
			check[next] = 0;
		}
	}
}

int main(void){

 	scanf("%d %d", &N, &M);
 	
 	for(int i = 0; i < M; i++){
 		scanf("%d %d", &a, &b);
 		map[a].push_back(b);
 		map[b].push_back(a);
	}
	
	for(int i = 0; i < N; i++){
	
		memset(check, 0, sizeof(check));
		check[i] = 1; // 방문 
		DFS(i, 0);
		
		if(answer) break;  
	}
	 	
 	printf("%d", answer);
 	
	return 0;
} 


