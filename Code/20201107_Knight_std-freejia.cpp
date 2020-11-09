#include <iostream> 
#include <queue>
#include <cstring> // memset()
#include <algorithm> // min(), pair STL
#define M_MAX 300
using namespace std;


int M[M_MAX+1][M_MAX+1]; // 체스판  
int M_LIMIT; // 체스판 크기 

int a,b, x,y; // 현재좌표, 목적좌표  

// 8방향 
int dx[10] = {1, 2, 2, 1, -2, -1, -2, -1}; 
int dy[10] = {2, 1, -1, -2, 1, 2, -1, -2};


// 범위 내에 있는지 확인
bool boundary(int i, int j){   

	return (i >= 0 && i < M_LIMIT && j >= 0 && j < M_LIMIT) ? 1:0;
} 


int BFS(){

	int cnt = 0;
	
	// q : 현재 좌표{a,b}와 이동 횟수cnt 저장  
	queue<pair<pair<int,int>,int>> q;	

	q.push({{a, b}, cnt} ); // 현재좌표 푸시  
	M[a][b] = 1; // 현재좌표 방문표시
	 
	while(!q.empty()){
	
		pair<pair<int,int>,int> now = q.front();
		q.pop();
		
		int nx = now.first.first; // 현재 좌표  
		int ny = now.first.second; 
		int cnt = now.second; // cnt 
		
		// 목적지라면 종료 
		if(nx == x && ny == y){
			return cnt;
		} 

		// 8 방향 확인  
		for(int i = 0; i < 8; i++){ // 범위 내부인지 확인 , 안가봤는지 확인, 가보면서 cnt++
			
			int tmpX = nx + dx[i]; // 가볼 좌표  
			int tmpY = ny + dy[i];
			
			if(boundary(tmpX, tmpY)){ // 범위 내부이면 
				
				if(M[tmpX][tmpY] == 0){ // 안가봤다면  
					
					q.push({ {tmpX, tmpY}, cnt+1} ); // 큐에 푸시
					M[tmpX][tmpY] = 1; //방문표시   
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
		cin >> a >> b >> x >> y; // 현재좌표, 목적좌표 
		memset(M, 0, sizeof(M));
 		cout << BFS() << '\n';	
		
 	}
	
	return 0;	
}
