#include <iostream> 
#include <queue>
#include <cstring> // memset()
#include <algorithm> // min(), pair STL
#define M_MAX 50
using namespace std;

int M[M_MAX+1][M_MAX+1]; //����  
int w, h; // �ʺ�, ����  

int dx[10] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int dy[10] = {-1, 0, 1, -1, 1, -1, 0, 1};


bool boundary(int i, int j){   // ����üũ  
	return (i >= 0 && i < h && j >= 0 && j < w);
} 

void BFS(int x, int y){  // ������ �� �������� ��ó ���� ���� �ٴٷ� �����. 
 
 	queue<pair<int,int>> q;
	
	q.push({x, y});  
	M[x][y] = 0;   
	
	while(!q.empty()){ // 1 �� 0�ٴ� 
	
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 8; i++){ // 8���� �˻�  
			
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			
			if(boundary(next_x, next_y) ){ // ���� �����̸�  
			
				if(M[next_x][next_y] == 1){ // ���̶�� 
				
					q.push({next_x, next_y}); // �湮�� ��ǥ ť�� �ֱ�  
					M[next_x][next_y] = 0; // �ٴٷ� �����  
				}
			}
		}
	}
 
}

int main(void){
  
	while(1){
			
		cin >> w >> h; // w, h  (��, ��)
		
		if(w==0 && h==0) break;
		
		// ���� �Է¹ޱ�  
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> M[i][j];
			}
		} 
		
		int cnt = 0; // ���� ����  
		
		for(int i = 0; i < h; i++){  // ������ Ž�� ( �� ã�� )
			for(int j = 0; j < w; j++){
			
				if(M[i][j] == 1){ // �� �߰�  
					BFS(i, j);
					cnt++;
				} 
				
 			}
		} 
		cout << cnt << '\n';
		
		memset(M, 0, sizeof(M));
	}
	
	return 0;	
}
