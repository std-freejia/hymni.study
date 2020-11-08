#include <iostream>
#include <stdio.h>
#include <algorithm> 
#include <vector>
using namespace std;

// 연결요소의 개수 (BOJ 11724)  

int N, M; //  정점개수, 간선 개수  
vector<int> v[500001];
bool check[500001]; // 방문 

void DFS(int start){

	check[start] = true; // 방문표시  
	
	for(int i = 0; i < v[start].size(); i++){
		int next_v = v[start][i];
		 
		if(check[next_v]) continue; // 방문했으면 지나감.
		else DFS(next_v);
	}
}

void solve(){

	int answer = 0;
	for(int i = 1; i <= N; i++){ // 모든 정점을 시작으로 탐색  
		if(!check[i]){
			answer++;
			DFS(i); 
		}
	}
	cout << answer;
 
}

void input(){
 
	cin >> N >> M; // 정점 개수, 간선 개수 
	
	int a=0, b=0;
	for(int i = 0 ; i<M; i++){ // 연결리스트 만들기  
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	 
}

int main() {	

 	input();
 	solve();

	return 0;
} 
