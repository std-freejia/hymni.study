#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#include <utility> 
using namespace std;

int N;
vector<int> danzi_v;  

int danzi[26][26];
int visit[26][26];

int direction[4][2] = { // 상하좌우 4방향  
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

bool boundary(int x, int y){

	return (x > 0 && x <= N && y > 0 && y <= N) ? 1:0;
}

int BFS(int start_x, int start_y){
	
	int cnt = 1; // 집 개수  
	queue<pair<int,int> > q;
	q.push({start_x, start_y});
	visit[start_x][start_y] = 1; //방문 표시  
	
	// 음수는 집이다. 
	
	while(!q.empty()){
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int next_x = now_x + direction[i][0];
			int next_y = now_y + direction[i][1];
			
			if(!boundary(next_x, next_y)) continue; // 인덱스 범위 초과  
			if(visit[next_x][next_y]) continue; // 이미 방문  
			
			if(danzi[next_x][next_y] != -1) continue;
			 
			q.push({next_x, next_y});
			visit[next_x][next_y] = 1; // 방문표시
			danzi[next_x][next_y] = 0;  
			cnt++; // 집 개수  
 		}
		
		
	} 
	
	return cnt; 
}

void solve(){

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
		
			if(-1 == danzi[i][j]){ // 집을 만나면 탐색 시작  
				int cnt = BFS(i, j);
				danzi_v.push_back(cnt); 
				//cout << cnt << '\n';
			}
		}	
	} 
	
	sort(danzi_v.begin(), danzi_v.end() ); // 오름차순 정렬  
	
	cout << danzi_v.size() << '\n'; // 단지 총 개수  
	
	for(int i = 0; i < danzi_v.size(); i++){ // 각 단지의 집의 개수  
		cout << danzi_v[i] << '\n';
	}
 
} 

void input(){

	cin >> N;
	
	int i=0, j=0, n=0;  
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
		
			scanf("%1d", &n); // int 1개씩 입력받는다 
			if( n == 1 ){
				danzi[i][j] = -1; // 1은 -1로 바꾸어 저장  
			}else{
				danzi[i][j] = 0;
			}
 		}	
	}
	
}

int main() {	
 
 	input();
	solve(); 
	
	return 0;
} 
