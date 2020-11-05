#include <iostream>
#include <algorithm> 
#include <vector>
#include <queue>
#include <set>
using namespace std;

// BFS 스페셜 저지 (BOJ 16940) 

int N; // 정점 개수 
vector<int> B[100001]; // 인접리스트 
int visited[100001]; // 방문 체크 
queue<int> q, input_q;

int BFS(){

	while(!q.empty()){
		int current = q.front(); 
		q.pop();
		
		set<int> s; // 중복제외하고 정점 번호 저장할 set  
		
		for(int i : B[current]){ // 현재 노드의 인접 정점들이 있는지 확인   
			if(visited[i]) continue; // 이미 방문한것 제외
			visited[i] = true; // 방문표시  
			s.insert(i); // 방문 해야할 것들 set에 저장  
		}
		
		// input_q 순서 따라가기. 
		for(int i = 0; i < (int)s.size(); i++){
			if(input_q.empty()) return false; // 방문 할 정점 없음 종료  
			
			int candidate = input_q.front(); // 지금 방문할 순서의 정점. 
			input_q.pop();
			
			// 후보가 set에 없다면, 지금 방문할 순서의 정점이 현재정점과 인접하지 않으므로 종료.  
			if(s.find(candidate) == s.end()) return false;
			else q.push(candidate);
		}
	}
	
	return true;		
}

bool solve(){

	int first = input_q.front(); 
	input_q.pop();
	if(first != 1) return false; // 시작 정점은 1이어야 한다  
	
	visited[first] = true;
	
	q.push(first); // 방문했으니까 큐에 넣는다 
		
	bool answer = BFS(); // BFS 탐색 시작  
		
	return answer;
}

void input(){ // 문제의 입력받는다  

	cin >> N; // 정점 개수  
	int a=0, b=0; 
	
	for(int i = 1; i < N; i++){ // N-1개의 인접리스트 정보   
		cin >> a >> b;
		B[a].push_back(b);
		B[b].push_back(a);
	}
	
	for(int i = 0; i < N; i++){ // 주어진 방문 순서를 전부 큐에 넣는다  
		cin >> a;
		input_q.push(a);
	}
}

int main() {	

 	input(); 
 	
 	bool answer = solve();  
 	
 	cout << answer;
 	
	return 0;
} 
