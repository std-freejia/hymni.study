#include <iostream> 
#include <queue>
#include <algorithm>  
using namespace std;

// Two Dots (BOJ 16929) 지아  

// 이 게임의 핵심은 같은 색으로 이루어진 사이클을 찾는 것이다. 
// 시작점으로 돌아와야 한다. 

 
int N, M;   // 행, 열  
char B[51][51]; //지도  
int check[51][51]; //방문 표시할 지도

bool stop_flag = false;
int start_x, start_y; // 시작점을 '목적지'로 이용한다.  

// 4방향 
int dx[5] = {-1, 1, 0, 0}; 
int dy[5] = {0, 0, -1, 1};


// 지도 범위 내에 있는지 확인
bool boundary(int i, int j){   
	return (i >= 0 && i < N && j >= 0 && j < M) ? 1:0;
} 
 
void DFS(int now_x, int now_y, int cnt){  // cnt: 4번 이상 움직였는지. 

	if(stop_flag) return;
	 
	check[now_x][now_y] = 1; // 방문  
	 
	for(int i = 0; i<4; i++){ // 4방향 확인(dx, dy 활용) 
	
		int next_x = now_x + dx[i];
		int next_y = now_y + dy[i];
		
		if(!boundary(next_x, next_y)) continue;  // 범위 내 인지  

		if(B[start_x][start_y] != B[next_x][next_y]) continue; // 색깔이 같은지  
					
		if(check[next_x][next_y] == 0){ // 미방문인지 -> 맞다면 방문한다.  
		
			check[next_x][next_y] = 1; // 방문 체크 
			DFS(next_x, next_y, cnt+1); // 방문한다  
			check[next_x][next_y] = 0;
			
		}else{ // 방문이지만, 목적지인지. 
			
			if(next_x == start_x && next_y == start_y && cnt >= 4){  // 4번 이상 움직여서 목적지 도달 
				stop_flag = true; // 탐색 끝! 
				return;
			}
		} 
		
	}

} 
 
int main(void){
 
 	cin >> N >> M; 
	 
	for(int i = 0; i <N; i++){
		for(int j = 0; j < M; j++){
			cin >> B[i][j];
		}
	}  
	
	string res = "";
	
	for(int i = 0; i  < N ; i++){
		for(int j = 0; j < M ; j++){ // 시작점이 곧 목적지가 된다.  
 
 			if(!check[i][j]){
	 			start_x = i; // 목적지 설정  
				start_y = j;
				
				DFS(i, j, 1);
			 }
			
			if(stop_flag) break;

		}
	} 
	
	if(stop_flag) cout << "Yes";
	else cout << "No";
	
	return 0;	
}
