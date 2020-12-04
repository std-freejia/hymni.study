#include <iostream>
#include <algorithm> 
#include <vector>
#include <deque>
#include <utility>
#define MAX 101
using namespace std;
 
int N, M;  // ���� N, ����M
int map[MAX][MAX]; // ����  
int broken_cnt[MAX][MAX] = {-1, }; // // ���� �������� ���� �μ� Ƚ��
bool visit[MAX][MAX]; // �湮 ���� 
 
int xx[5] = {0, 0, -1, 1};
int yy[5] = {-1, 1, 0, 0};

deque<pair<int, int> > de;

bool check_boundary(int x, int y){
	return (x <= N && x >= 1 && y <= M && y >= 1 );
}

void BFS(int x, int y){ 
	
	de.push_back( {x, y});
	broken_cnt[x][y] = 0;
	
	visit[x][y] = true;
	
	while(!de.empty()){  
	
		int now_x = de.front().first;
		int now_y = de.front().second;
		de.pop_front();
	 		
		for(int i=0; i < 4; i++){
		
			int next_x = now_x + xx[i];
			int next_y = now_y + yy[i];
			
			if(check_boundary(next_x, next_y) == false) continue; // ��ǥ ���� üũ  
			
			if(true == visit[next_x][next_y]) continue; // �̹� �湮 
			
			
			if(map[next_x][next_y] == 1){  // 1. ���� �մ´�.  (+1)
				broken_cnt[next_x][next_y] = broken_cnt[now_x][now_y]+1; 
				visit[next_x][next_y] = true;
				de.push_back({next_x, next_y});
				
			}else if(map[next_x][next_y] == 0){ // 2. ����� �״��.  
				broken_cnt[next_x][next_y] = broken_cnt[now_x][now_y];
				visit[next_x][next_y] = true;
				de.push_front({next_x, next_y});
				
			}
		}
	
	}
}

void Solve(){
	BFS(1, 1);  // (1,1)���� ����. (N,M)�� ����
 	cout << broken_cnt[N][M];
}

void Input(){
	cin >> M >> N ;  
	
	for(int i = 1; i <= N; i++){ 	 
		for(int j = 1; j <= M; j++){
			scanf("%1d", &map[i][j]);   
 		}
	} 
}

int main(void){
 
	Input();
	
	Solve();   

	return 0;
} 

