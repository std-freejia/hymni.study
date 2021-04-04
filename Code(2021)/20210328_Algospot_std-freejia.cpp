#include <iostream>
#include <algorithm> 
#include <vector>
#include <deque>
#include <utility>
#define MAX 101
using namespace std;

// 알고스팟 BOJ 13549
 
int N, M, answer;
int map[MAX][MAX]; // 지도  (0은 빈 방, 1은 벽)
int broken_cnt[MAX][MAX] = {-1, }; // // 현재 지점에서 벽을 부순 횟수

// 4방향 이동
int xx[5] = {0, 0, -1, 1};
int yy[5] = {-1, 1, 0, 0};

deque<pair<int, int> > de;  // 벽을 뚫는 경우 에는 뒤에, 안뚫는 경우에는 앞에 추가한다. 

bool check_boundary(int x, int y){
	return (x <= N && x >= 1 && y <= M && y >= 1 );
}

void BFS(){ // (1,1)에서 시작해서 (N,M)에 도착해야 한다.  
	
	de.push_back( {1, 1});
	broken_cnt[1][1] = 0;
	
	while(!de.empty()){  
	
		int now_x = de.front().first ;
		int now_y = de.front().second;
		de.pop_front();
		
 		
		int now_cnt = broken_cnt[now_x][now_y]; // 현재 지점에서 벽을 부순 횟수  
	
		for(int i=0; i < 4; i++){
			int next_x = now_x + xx[i];
			int next_y = now_y + yy[i];
			
			if(check_boundary(next_x, next_y) == false) continue; // 좌표 범위 체크  
			
			if(broken_cnt[next_x][next_y] != -1) continue; // 이미 방문했다면 지나간다. 
			
			if(map[next_x][next_y] == 1){  // 벽이면 뚫는다.  
				broken_cnt[next_x][next_y] = now_cnt+1; 
				de.push_back({next_x, next_y});
			}else if(map[next_x][next_y] == 0){ // 빈방이면 안뚫어도 된다  
				broken_cnt[next_x][next_y] = broken_cnt[now_x][now_y];
				de.push_front({next_x, next_y});
				
			}
		}
	
	}
}

void Solve(){

	BFS();
 	cout << broken_cnt[N][M];
}

void Input(){

	cin >> M >> N ; // 가로M, 세로 N
	char ch = 0;
	
	for(int i = 1; i <= N; i++){ 	//map 입력받기
		for(int j = 1; j <= M; j++){
			scanf("%1d", &map[i][j]);
			broken_cnt[i][j] = -1;
		}
	} 
}

int main(void){
 
	Input();
	
	Solve();   

	return 0;
} 
