#include <iostream>
#include <algorithm> 
#include <vector>
#include <deque>
#include <utility>
#define MAX 101
using namespace std;

// �˰���  (BOJ 1261) ����  
 
int N, M;
int map[MAX][MAX]; // ����  
int broken_cnt[MAX][MAX] = {-1, }; // // ���� �������� ���� �μ� Ƚ��

int xx[5] = {0, 0, -1, 1};
int yy[5] = {-1, 1, 0, 0};

deque<pair<int, int> > de;

bool check_boundary(int x, int y){ // ��ǥ ���� üũ  
	return (x <= N && x >= 1 && y <= M && y >= 1 );
}

void BFS(){ // (1,1)���� �����ؼ� (N,M)�� �����ؾ� �Ѵ�.  
	
	de.push_back( {1, 1});
	broken_cnt[1][1] = 0; // �ϴ� �湮�ϸ� 0 
	
	while(!de.empty()){  
	
		int now_x = de.front().first ;
		int now_y = de.front().second;
		de.pop_front();
	 		
		int now_cnt = broken_cnt[now_x][now_y]; // ���� �������� ���� �μ� Ƚ��  
		
		for(int i=0; i < 4; i++){
			int next_x = now_x + xx[i];
			int next_y = now_y + yy[i];
			
			if(check_boundary(next_x, next_y) == false) continue; // ��ǥ ���� üũ  
			
			if(broken_cnt[next_x][next_y] != -1) continue; // �̹� �湮�ߴٸ� ��������. 
			
			if(map[next_x][next_y] == 1){  // ���̸� �մ´�.  
				broken_cnt[next_x][next_y] = now_cnt+1; 
				de.push_back({next_x, next_y});
                
			}else if(map[next_x][next_y] == 0){ // ����̸� �ȶվ �ȴ�  
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

	cin >> M >> N ; // ����M, ���� N
	
	for(int i = 1; i <= N; i++){ 	//map �Է¹ޱ�
		for(int j = 1; j <= M; j++){
			scanf("%1d", &map[i][j]);  // ���� 1���� �Է� ���� ���� 1d �� ����. 
			broken_cnt[i][j] = -1;  // ���� -1�� �ʱ�ȭ 
		}
	} 
}

int main(void){
 
	Input();
	
	Solve();   

	return 0;
} 
