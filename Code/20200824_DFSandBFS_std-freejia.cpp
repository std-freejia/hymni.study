#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// DFS BFS

int N, M; // ����, ���� ��  
int map[1001][1001]; // ��������Ʈ  
int check[1001]; // ���� �湮 ����  
queue<int> qu;	  

void DFS(int v){
	
	check[v] = 1; // �湮 
	
	cout << v << ' ';
	
	for(int i = 1; i <= N; i++){
		if(map[v][i] != 0 && check[i] == 0){
			DFS(i); 
		}
	} 

}

void BFS(int v){
	
	qu.push(v); // ù ���� �湮  
	check[v] = 1; 

	while(!qu.empty()){
	
		//������ ������
		v = qu.front();
		qu.pop();
		cout << v << ' ';
		
		for(int i = 1; i <= N; i++){ // v ������ ����� ��带 ã�´�.  
		 
			if(check[i] == 0 && map[v][i]) { // ù �湮�̶��, 
			
				check[i] = 1; // �湮ǥ�� 
				qu.push(i); // ť�� Ǫ�� 
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
		map[b][a] = 1; // ������ ����� 
	}
	

 	DFS(startV);
 	cout << '\n';
	
	memset(check, 0, sizeof(check)); // �湮 üũ �迭 0���� �ʱ�ȭ  
	BFS(startV);
 
	
	return 0;
}



