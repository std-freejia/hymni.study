#include <iostream> 
#include <vector>
#include <cstring> // memset()
#include <algorithm>
#define MAX 2000
using namespace std;

// ABCDE

/*
depth가 4인 순간 true를 리턴하면 된다.  
*/
 
int N, M;
int answer = 0;
vector<int> V[MAX];
int visited[MAX+1];

void DFS(int idx, int depth){

	if(depth == 4){ //  0,1,2,3,4 로 이어진 depth 4 라면 answer 1 로 갱신 
		answer = 1;
		return;
	}
	
	visited[idx] = 1; // 현재 노드 방문 표시 
	
	for(int i = 0; i < V[idx].size(); i ++){
	
		int next = V[idx][i]; // 다음 노드 
		
		if(!visited[next]){ // 다음 노드가 안가본 노드라면, 가본다. 
			visited[next] = 1;
			DFS(next, depth+1);
			visited[next] = 0;
		}
	}
}

void input(){

	cin >> N >> M; // 노드, 간선 개수  
 
 	int start=0, end=0;
 	
 	for(int i = 0; i < M; i++){ // 간선 개수 만큼 입력
		cin >> start >> end;
		V[start].push_back(end);
		V[end].push_back(start); 
	}    
}

int main(void){
 
	input(); // 입력받기  
	
	// 시작 노드를 바꿔가며 0,1,2,3,4 로 이어진 depth 있는지 확인  
	for(int i = 0; i < N; i++){
		
		memset(visited, 0, sizeof(visited)); // 방문 배열 초기화  
		visited[i] = 1;
		DFS(i, 0); 
		
		if(answer == 1) break; 
	}
	
 	cout << answer;
 	
	return 0;	
}
