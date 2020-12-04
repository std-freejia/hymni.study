#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000+1 
 
using namespace std;
   
int M, N; // 가로, 세로 
int A[MAX][MAX];
int zero_cnt, ripe, day;
queue<pair<int,int> > q;


// 상 하 좌 우
int diff_x[4] = {-1, 1, 0, 0};  // N  
int diff_y[4] = {0, 0, -1, 1};  // M


bool boundary(int x, int y){ 
	return (x < N && x >= 0 && y < M && y >= 0);
}

void BFS(){

	while(!q.empty()){
		
		pair<int,int> now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i ++){ // 상하좌우 확인 
		
			int x = now.first + diff_x[i];
			int y = now.second + diff_y[i];
			 
			if(boundary(x, y) && A[x][y] == 0){ // 범위 안에 있고, 안 익었으면. 
				A[x][y] = A[now.first][now.second] + 1; 
				q.push(make_pair(x, y));
				ripe++; // 익은 개수 
				day = max(A[x][y], day); // day 증가됬다면 갱신 
			}
		}
	
	}

	if(zero_cnt > ripe) { // 모두 익지 못한다. 
		cout << -1; 
	}else{
		cout << day-1;
	}
	
}

int main(void){

	cin >> M >> N; // 가로, 세로  
 	
	for(int i = 0; i < N; i++){ // 세로 N
	
		for(int j = 0; j < M; j++){ // 가로 M 
            
			scanf("%d", &A[i][j]);
			if(A[i][j] == 0) zero_cnt++; // 안익은 토마토 개수 센다  
			else if(A[i][j] == 1) {
				q.push(make_pair(i, j)); // 가능한 시작점 모두 넣는다  
			}
		} 
	} // 입력받기 끝
	
	if(zero_cnt == 0) cout << 0; // 저장될 때부터 모든 토마토가 익어있는 상태
	else{ // 탐색시작 
		BFS(); 
	}
	
	return 0;	
}
