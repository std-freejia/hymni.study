#include <iostream> 
#include <vector>
#include <cstring> // memset()
#include <algorithm>
#define MAX 2000
using namespace std;

// ABCDE

/*
depth�� 4�� ���� true�� �����ϸ� �ȴ�.  
*/
 
int N, M;
int answer = 0;
vector<int> V[MAX];
int visited[MAX+1];

void DFS(int idx, int depth){

	if(depth == 4){ //  0,1,2,3,4 �� �̾��� depth 4 ��� answer 1 �� ���� 
		answer = 1;
		return;
	}
	
	visited[idx] = 1; // ���� ��� �湮 ǥ�� 
	
	for(int i = 0; i < V[idx].size(); i ++){
	
		int next = V[idx][i]; // ���� ��� 
		
		if(!visited[next]){ // ���� ��尡 �Ȱ��� �����, ������. 
			visited[next] = 1;
			DFS(next, depth+1);
			visited[next] = 0;
		}
	}
}

void input(){

	cin >> N >> M; // ���, ���� ����  
 
 	int start=0, end=0;
 	
 	for(int i = 0; i < M; i++){ // ���� ���� ��ŭ �Է�
		cin >> start >> end;
		V[start].push_back(end);
		V[end].push_back(start); 
	}    
}

int main(void){
 
	input(); // �Է¹ޱ�  
	
	// ���� ��带 �ٲ㰡�� 0,1,2,3,4 �� �̾��� depth �ִ��� Ȯ��  
	for(int i = 0; i < N; i++){
		
		memset(visited, 0, sizeof(visited)); // �湮 �迭 �ʱ�ȭ  
		visited[i] = 1;
		DFS(i, 0); 
		
		if(answer == 1) break; 
	}
	
 	cout << answer;
 	
	return 0;	
}
