#include <iostream> 
#include <vector>
#include <queue>
#include <cstring> // memset()
#include <algorithm>
#define MAX_SIZE 20000+1
#define RED 1
#define BLUE 2
using namespace std;

// �̺б׷���  (BOJ 1707)

int K, V, E; // ����, ���� ����  
vector<int> G[MAX_SIZE]; 
int check[MAX_SIZE]; // �̹湮 0, RED 1, BLUE 2 

void BFS(int start){

	queue<int> q;
	int color = RED;
	
	check[start] = color;
	q.push(start);
	
	while(!q.empty()){
	
		int now = q.front(); // ���� ����  
		q.pop();
		
		if(check[now] == RED){ // ���� ����� �ٸ��� �ٲ۴�.  
			color = BLUE;
		}else{
			color = RED;
		}
		
		int adj_size = G[now].size(); 

		for(int i = 0; i < adj_size; i++){
			int next = G[now][i];
			
			if(!check[next]){
				check[next] = color; // ���� ĥ�ϰ� ť�� �ִ´�  
				q.push(next);
			}
		}
	}	
} 

bool is_bipartite(){
	
	for(int i = 1; i <= V; i++){ // ��� ������ '���� ������'�� Ȯ������  
		
		int size = G[i].size();
		
		for(int j = 0; j <size; j++){ // i ������ ���� ���� ��� Ȯ��  
			int next = G[i][j];
			if(check[next] == check[i]){
				return false;
			}	
		}
	}
	
	return true;
}
 
void input(){
 
	cin >> K; // �׽�Ʈ ���̽� ����  
	
	while(K--){
		cin >> V >> E; // ���� ����, ���� ���� 
	
		int a=0, b=0;	

		for(int i = 0 ; i< E; i++){ // ���Ḯ��Ʈ �����  
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		for(int i = 1; i <= V; i++){ // BFS�� Ž��  
 			if(!check[i]) {
 				BFS(i);
			 }
		}
 
		string answer = (is_bipartite()) ? "YES" : "NO"; 
 		cout << answer << '\n';
 		
 		memset(check, 0, sizeof(check)); // �湮 �迭 �ʱ�ȭ 
 		for(int i = 0; i <= V; i++){ // ���� ���� 0 �ʱ�ȭ  
 			G[i].clear();
		}
	}
}

int main() {	

 	input();

	return 0;
} 
