#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000+1 
 
using namespace std;
   
int M, N; // ����, ���� 
int A[MAX][MAX];
int zero_cnt, ripe, day;
queue<pair<int,int> > q;


// �� �� �� ��
int diff_x[4] = {-1, 1, 0, 0};  // N  
int diff_y[4] = {0, 0, -1, 1};  // M


bool boundary(int x, int y){ 
	return (x < N && x >= 0 && y < M && y >= 0);
}

void BFS(){

	while(!q.empty()){
		
		pair<int,int> now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i ++){ // �����¿� Ȯ�� 
		
			int x = now.first + diff_x[i];
			int y = now.second + diff_y[i];
			 
			if(boundary(x, y) && A[x][y] == 0){ // ���� �ȿ� �ְ�, �� �;�����. 
				A[x][y] = A[now.first][now.second] + 1; 
				q.push(make_pair(x, y));
				ripe++; // ���� ���� 
				day = max(A[x][y], day); // day ������ٸ� ���� 
			}
		}
	
	}

	if(zero_cnt > ripe) { // ��� ���� ���Ѵ�. 
		cout << -1; 
	}else{
		cout << day-1;
	}
	
}

int main(void){

	cin >> M >> N; // ����, ����  
 	
	for(int i = 0; i < N; i++){ // ���� N
	
		for(int j = 0; j < M; j++){ // ���� M 
            
			scanf("%d", &A[i][j]);
			if(A[i][j] == 0) zero_cnt++; // ������ �丶�� ���� ����  
			else if(A[i][j] == 1) {
				q.push(make_pair(i, j)); // ������ ������ ��� �ִ´�  
			}
		} 
	} // �Է¹ޱ� ��
	
	if(zero_cnt == 0) cout << 0; // ����� ������ ��� �丶�䰡 �;��ִ� ����
	else{ // Ž������ 
		BFS(); 
	}
	
	return 0;	
}
