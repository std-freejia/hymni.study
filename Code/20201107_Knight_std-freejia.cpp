#include <iostream> 
#include <queue>
#include <cstring> // memset()
#include <algorithm>
 
using namespace std;

// ����Ʈ�� �̵�(BOJ 7562)  

int TC, N, answer; // �׽�Ʈ���̽�, ü���� �� ���� ����
int map[301][301]; 
int start_x, start_y, dest_x, dest_y; // ��������, ��������  

int xx[9] = {-2, -1, 1, 2, -2, -1, 1, 2};
int yy[9] = {-1, -2, 2, 1, 1, 2, -2, -1};

bool boundary(int x, int y){
	return (x >= 0 && x < N && y >= 0 && y < N)? 1:0;
}

void BFS(){
	
	queue<pair<pair<int,int>, int> > q;
	
	q.push({{start_x, start_y}, 0}); // �������� ť�� �ֱ�  
	map[start_x][start_y] = 1; // �湮ǥ�� 
	
	while(!q.empty()){
	
		int now_x = q.front().first.first;
		int now_y = q.front().first.second;
		int now_cnt = q.front().second;
		
		q.pop();
		
		if(now_x == dest_x && now_y == dest_y){ // ������ �����ϸ� Ż��  
			answer = now_cnt; 
			break;
		} 
		
		for(int i = 0; i < 8; i++){ // 8���� ��� Ȯ��  
			int next_x = now_x + xx[i];
			int next_y = now_y + yy[i];
			
			if(false == boundary(next_x, next_y)) continue; // �ε��� Ȯ�� 
			if(1 == map[next_x][next_y]) continue; // �湮�߾����� Ȯ��  
			
			q.push({{next_x, next_y}, now_cnt+1}); // ť�� Ǫ��  
			map[next_x][next_y] = 1; // �湮ǥ��  
		}
	} 
	
	
}

void input(){

	cin >> TC; 
	
	while(TC--){
		
		cin >> N; // ü���� ����  
		
		scanf("%d %d %d %d", &start_x, &start_y, &dest_x, &dest_y);
		
		BFS(); // Ž��  
		
		cout << answer << '\n';
		
		memset(map, 0, sizeof(map)); // �湮 �迭 �ʱ�ȭ  
		
		answer = 0;
	}
}

int main() {	

 	input();

	return 0;
} 
