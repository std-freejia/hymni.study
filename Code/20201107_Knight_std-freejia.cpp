#include <iostream> 
#include <queue>
#include <cstring> // memset()
#include <algorithm> // min(), pair STL
#define M_MAX 300
using namespace std;


int M[M_MAX+1][M_MAX+1]; // ü����  
int M_LIMIT; // ü���� ũ�� 

int a,b, x,y; // ������ǥ, ������ǥ  

// 8���� 
int dx[10] = {1, 2, 2, 1, -2, -1, -2, -1}; 
int dy[10] = {2, 1, -1, -2, 1, 2, -1, -2};


// ���� ���� �ִ��� Ȯ��
bool boundary(int i, int j){   

	return (i >= 0 && i < M_LIMIT && j >= 0 && j < M_LIMIT) ? 1:0;
} 


int BFS(){

	int cnt = 0;
	
	// q : ���� ��ǥ{a,b}�� �̵� Ƚ��cnt ����  
	queue<pair<pair<int,int>,int>> q;	

	q.push({{a, b}, cnt} ); // ������ǥ Ǫ��  
	M[a][b] = 1; // ������ǥ �湮ǥ��
	 
	while(!q.empty()){
	
		pair<pair<int,int>,int> now = q.front();
		q.pop();
		
		int nx = now.first.first; // ���� ��ǥ  
		int ny = now.first.second; 
		int cnt = now.second; // cnt 
		
		// ��������� ���� 
		if(nx == x && ny == y){
			return cnt;
		} 

		// 8 ���� Ȯ��  
		for(int i = 0; i < 8; i++){ // ���� �������� Ȯ�� , �Ȱ��ô��� Ȯ��, �����鼭 cnt++
			
			int tmpX = nx + dx[i]; // ���� ��ǥ  
			int tmpY = ny + dy[i];
			
			if(boundary(tmpX, tmpY)){ // ���� �����̸� 
				
				if(M[tmpX][tmpY] == 0){ // �Ȱ��ôٸ�  
					
					q.push({ {tmpX, tmpY}, cnt+1} ); // ť�� Ǫ��
					M[tmpX][tmpY] = 1; //�湮ǥ��   
				}
			}
		} 
	}
}

int main(void){
 
 	int TC = 0;
 	
	cin >> TC;
	
	while(TC--){
	
		cin >> M_LIMIT; 
		cin >> a >> b >> x >> y; // ������ǥ, ������ǥ 
		memset(M, 0, sizeof(M));
 		cout << BFS() << '\n';	
		
 	}
	
	return 0;	
}
