#include <iostream>
#include <algorithm> 
#include <cstring> // memset()
#include <vector>
#include <string>
#include <queue>
using namespace std;

//  �ٸ� ����� ( BOJ 2146)  
 
int N; // �ʺ�(����), ����
int map[101][101]; // 1��, 0�ٴ�   
int visited[101][101]; 

int dxx[4] = {0, 0, -1, 1}; 
int dyy[4] = {-1, 1, 0, 0};

int minlen_bridge = 2e9; 


bool boundary_check(int i, int j){ // ���� ����  
	return (i >= 0 && i < N && j >= 0 && j < N) ? true : false;
}

void numbering_BFS(int x, int y, int island_num){

	queue<pair<int, int> > qu;
	
	qu.push({x, y}); // ������ 
	
	while(!qu.empty()){
		int now_x = qu.front().first;
		int now_y = qu.front().second;
		qu.pop();

		for(int i = 0; i < 4; i++){ // 4���� �˻��Ѵ� 
			 
			int next_x = dxx[i] + now_x;
			int next_y = dyy[i] + now_y;
			 
			if(boundary_check(next_x, next_y) == false) continue; // ���� �ʰ��� ��������.  

			if(map[next_x][next_y] == -1) {	//  ó�� ���� ���̶�� ť�� Ǫ��  
				qu.push({next_x, next_y});
				map[next_x][next_y] = island_num;   // �� ��ȣ ���δ�.  
			}
			
		} 
	}
}

int connecting_BFS(int island_num){

	queue<pair<int, int> > qu;

	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			if(map[x][y] == island_num ){
				visited[x][y] = 1;
				qu.push({x, y});
			}
		}
	}
	
	int distance = 0;
	
	while(!qu.empty()){

		int qu_size = qu.size();
		
		for(int q = 0; q < qu_size; q++ ){

			int now_x = qu.front().first;
			int now_y = qu.front().second;
			qu.pop();
	
			for(int i = 0; i < 4; i++){ // 4���� �˻��Ѵ� 
				 
				int next_x = dxx[i] + now_x;
				int next_y = dyy[i] + now_y;

				if(boundary_check(next_x, next_y) == false) continue; // ���� �ʰ��� ��������. 
				
				if(map[next_x][next_y] > 0 && map[next_x][next_y] != island_num){ // �ٸ� ���̸�. 
					return distance;
				} 
				
				else if(map[next_x][next_y] == 0 && !visited[next_x][next_y]){ // ó�� �湮�� �ٴٶ�� 	 
					visited[next_x][next_y] = 1;
					qu.push({next_x, next_y});
	
				}
				
			} 
		}
		
		distance++;
	}

	//return 0;
} 

void Solve(){

	int island_num = 0; 
	 
 	for(int i = 0; i < N; i++){ // �� �߰� �� �� ���� BFS Ž�� ���� 
		for(int j = 0; j < N; j++){
			if(map[i][j] == -1) { // �� �߰�  
				numbering_BFS(i, j, ++island_num);  // ������ �ε����� �� ��ȣ �ѱ��
			}
		}
	}
	
	/*
	cout << "�� ���� : " << island_num << '\n';
	
	// �� ��ȣ ���� ���  ���  
 	for(int i = 0; i < N; i++){  
		for(int j = 0; j < N; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	
	for(int i = 0; i < island_num; i++){  
		memset(visited, 0, sizeof(visited)); 
		int length_of_bridge = connecting_BFS(i);
		//printf("%d\n", length_of_bridge);
		if(length_of_bridge != 0) minlen_bridge = min(minlen_bridge, length_of_bridge);  // ������ �����ؼ� �ٸ� ����  
		
	}
	
	cout << minlen_bridge;
	
}

void Input(){
	
	freopen("input.txt", "rt", stdin);
 
	cin >> N;

	for(int i = 0; i < N; i++){ // ���� �Է� �ޱ�  
		for(int j = 0; j < N; j++){
		
			int num = 0;
			scanf("%d", &num);
			
			if(num == 1) map[i][j] = -1; // ���̸� -1
			else map[i][j] = 0; // �ٴٴ� 0 
		}
	}
	
	Solve();

}

int main(void){

	Input();

	return 0;
} 

