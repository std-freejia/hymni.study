#include <iostream> 
#include <queue>
#include <cstring> // memset()
#include <algorithm>
 
using namespace std;

// 나이트의 이동(BOJ 7562)  

int TC, N, answer; // 테스트케이스, 체스판 한 변의 길이
int map[301][301]; 
int start_x, start_y, dest_x, dest_y; // 시작지점, 목적지점  

int xx[9] = {-2, -1, 1, 2, -2, -1, 1, 2};
int yy[9] = {-1, -2, 2, 1, 1, 2, -2, -1};

bool boundary(int x, int y){
	return (x >= 0 && x < N && y >= 0 && y < N)? 1:0;
}

void BFS(){
	
	queue<pair<pair<int,int>, int> > q;
	
	q.push({{start_x, start_y}, 0}); // 시작지점 큐에 넣기  
	map[start_x][start_y] = 1; // 방문표시 
	
	while(!q.empty()){
	
		int now_x = q.front().first.first;
		int now_y = q.front().first.second;
		int now_cnt = q.front().second;
		
		q.pop();
		
		if(now_x == dest_x && now_y == dest_y){ // 목적지 도착하면 탈출  
			answer = now_cnt; 
			break;
		} 
		
		for(int i = 0; i < 8; i++){ // 8방향 모두 확인  
			int next_x = now_x + xx[i];
			int next_y = now_y + yy[i];
			
			if(false == boundary(next_x, next_y)) continue; // 인덱스 확인 
			if(1 == map[next_x][next_y]) continue; // 방문했었는지 확인  
			
			q.push({{next_x, next_y}, now_cnt+1}); // 큐에 푸시  
			map[next_x][next_y] = 1; // 방문표시  
		}
	} 
	
	
}

void input(){

	cin >> TC; 
	
	while(TC--){
		
		cin >> N; // 체스판 길이  
		
		scanf("%d %d %d %d", &start_x, &start_y, &dest_x, &dest_y);
		
		BFS(); // 탐색  
		
		cout << answer << '\n';
		
		memset(map, 0, sizeof(map)); // 방문 배열 초기화  
		
		answer = 0;
	}
}

int main() {	

 	input();

	return 0;
} 
