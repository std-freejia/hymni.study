#include <iostream> 
#include <queue>
#include <cstring> // memset()
#include <algorithm> // min(), pair STL
#define M_MAX 50
using namespace std;

int M[M_MAX+1][M_MAX+1]; //지도  
int w, h; // 너비, 높이  

int dx[10] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int dy[10] = {-1, 0, 1, -1, 1, -1, 0, 1};


bool boundary(int i, int j){   // 범위체크  
	return (i >= 0 && i < h && j >= 0 && j < w);
} 

void BFS(int x, int y){  // 시작점 땅 기준으로 근처 땅을 전부 바다로 만든다. 
 
 	queue<pair<int,int>> q;
	
	q.push({x, y});  
	M[x][y] = 0;   
	
	while(!q.empty()){ // 1 땅 0바다 
	
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 8; i++){ // 8방향 검사  
			
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			
			if(boundary(next_x, next_y) ){ // 범위 내부이면  
			
				if(M[next_x][next_y] == 1){ // 땅이라면 
				
					q.push({next_x, next_y}); // 방문한 좌표 큐에 넣기  
					M[next_x][next_y] = 0; // 바다로 만든다  
				}
			}
		}
	}
 
}

int main(void){
  
	while(1){
			
		cin >> w >> h; // w, h  (열, 행)
		
		if(w==0 && h==0) break;
		
		// 지도 입력받기  
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> M[i][j];
			}
		} 
		
		int cnt = 0; // 섬의 개수  
		
		for(int i = 0; i < h; i++){  // 시작점 탐색 ( 땅 찾기 )
			for(int j = 0; j < w; j++){
			
				if(M[i][j] == 1){ // 땅 발견  
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
