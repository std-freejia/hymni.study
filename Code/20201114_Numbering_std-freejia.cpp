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

int direction[4][2] = { // �����¿� 4����  
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

bool boundary(int x, int y){

	return (x > 0 && x <= N && y > 0 && y <= N) ? 1:0;
}

int BFS(int start_x, int start_y){
	
	int cnt = 1; // �� ����  
	queue<pair<int,int> > q;
	q.push({start_x, start_y});
	visit[start_x][start_y] = 1; //�湮 ǥ��  
	
	// ������ ���̴�. 
	
	while(!q.empty()){
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int next_x = now_x + direction[i][0];
			int next_y = now_y + direction[i][1];
			
			if(!boundary(next_x, next_y)) continue; // �ε��� ���� �ʰ�  
			if(visit[next_x][next_y]) continue; // �̹� �湮  
			
			if(danzi[next_x][next_y] != -1) continue;
			 
			q.push({next_x, next_y});
			visit[next_x][next_y] = 1; // �湮ǥ��
			danzi[next_x][next_y] = 0;  
			cnt++; // �� ����  
 		}
		
		
	} 
	
	return cnt; 
}

void solve(){

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
		
			if(-1 == danzi[i][j]){ // ���� ������ Ž�� ����  
				int cnt = BFS(i, j);
				danzi_v.push_back(cnt); 
				//cout << cnt << '\n';
			}
		}	
	} 
	
	sort(danzi_v.begin(), danzi_v.end() ); // �������� ����  
	
	cout << danzi_v.size() << '\n'; // ���� �� ����  
	
	for(int i = 0; i < danzi_v.size(); i++){ // �� ������ ���� ����  
		cout << danzi_v[i] << '\n';
	}
 
} 

void input(){

	cin >> N;
	
	int i=0, j=0, n=0;  
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
		
			scanf("%1d", &n); // int 1���� �Է¹޴´� 
			if( n == 1 ){
				danzi[i][j] = -1; // 1�� -1�� �ٲپ� ����  
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
