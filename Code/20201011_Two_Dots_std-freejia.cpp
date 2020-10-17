#include <iostream> 
#include <queue>
#include <algorithm>  
using namespace std;

// Two Dots (BOJ 16929) ����  

// �� ������ �ٽ��� ���� ������ �̷���� ����Ŭ�� ã�� ���̴�. 
// ���������� ���ƿ;� �Ѵ�. 

 
int N, M;   // ��, ��  
char B[51][51]; //����  
int check[51][51]; //�湮 ǥ���� ����

bool stop_flag = false;
int start_x, start_y; // �������� '������'�� �̿��Ѵ�.  

// 4���� 
int dx[5] = {-1, 1, 0, 0}; 
int dy[5] = {0, 0, -1, 1};


// ���� ���� ���� �ִ��� Ȯ��
bool boundary(int i, int j){   
	return (i >= 0 && i < N && j >= 0 && j < M) ? 1:0;
} 
 
void DFS(int now_x, int now_y, int cnt){  // cnt: 4�� �̻� ����������. 

	if(stop_flag) return;
	 
	check[now_x][now_y] = 1; // �湮  
	 
	for(int i = 0; i<4; i++){ // 4���� Ȯ��(dx, dy Ȱ��) 
	
		int next_x = now_x + dx[i];
		int next_y = now_y + dy[i];
		
		if(!boundary(next_x, next_y)) continue;  // ���� �� ����  

		if(B[start_x][start_y] != B[next_x][next_y]) continue; // ������ ������  
					
		if(check[next_x][next_y] == 0){ // �̹湮���� -> �´ٸ� �湮�Ѵ�.  
		
			check[next_x][next_y] = 1; // �湮 üũ 
			DFS(next_x, next_y, cnt+1); // �湮�Ѵ�  
			check[next_x][next_y] = 0;
			
		}else{ // �湮������, ����������. 
			
			if(next_x == start_x && next_y == start_y && cnt >= 4){  // 4�� �̻� �������� ������ ���� 
				stop_flag = true; // Ž�� ��! 
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
		for(int j = 0; j < M ; j++){ // �������� �� �������� �ȴ�.  
 
 			if(!check[i][j]){
	 			start_x = i; // ������ ����  
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
