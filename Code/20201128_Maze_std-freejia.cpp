#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
   
int N, M;  // 행, 열  
int A[MAX][MAX];
// 1 이동 가능 , 0 이동 불가

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; 

bool boundary(int i, int j){ // 범위 체크 
	return (i >= 0 && i < N && j >=0 && j < M);
}

void BFS(){

	queue<pair<int,int> > q;
	q.push(make_pair(0, 0));
	
	while(!q.empty()){
		
		pair<int,int> now = q.front();
		q.pop();
		
		int x = now.first;
		int y = now.second;
		
		for(int i = 0; i < 4; i++){
		
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if(A[xx][yy] == 1 && boundary(xx, yy)){
				q.push(make_pair(xx, yy));
				A[xx][yy] = A[x][y] + 1;
			}
		}
	}
	
	
}  

void Input(){

	cin >> N >> M ;
 	
 	for(int i = 0 ; i < N; i++){
 	
 		char ch[MAX];
 		scanf("%s", &ch);
 		
 		for(int j = 0; j < M; j++){
	 		A[i][j] = ch[j]-48;  
		} 
	}  

}
 
int main(void){
 
	Input();
 	BFS();
	cout << A[N-1][M-1];
	
	return 0;	
}
