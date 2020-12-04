#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// DFS BFS

int N, M, sV; // ����, ���� �� , ��������.  
int map[1001][1001]; // ��������Ʈ  
int check[1001]; // ���� �湮 ����  
queue<int> qu;	  

void DFS(int v){
	
	check[v] = 1; // �湮 ǥ��  
	
	cout << v << ' ';
	
	for(int i = 1; i <= N; i++){
		if(map[v][i] != 0 && check[i] == 0){
			DFS(i); 
		}
	} 

}

void BFS(int v){
	
	qu.push(v);  
	check[v] = 1; // �湮ǥ��  

	while(!qu.empty()){
	
		v = qu.front();
		qu.pop();
		cout << v << ' ';
		
		for(int i = 1; i <= N; i++){  // �ֺ� Ž��  
		 
			if(check[i] == 0 && map[v][i]) { // ù �湮�̸�  
			
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
		map[b][a] = 1; //  ����� 
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



