#include <iostream> 
using namespace std;
  
int N, M; // �ڿ��� N, M 
int answer[10];

void DFS(int idx){
 
 	if(idx > M){ // M�� ���� �Ϸ�
		for(int i = 1; i <= M; i++){
			cout << answer[i] << ' ';
		} 
		cout << '\n';
		return;
	}
	
	for(int i = 1; i <= N; i++){ // �ߺ��� ���� �����ص� ������ 
		
		answer[idx] = i;
		DFS(idx+1);
	}
	
}

void solve(){
	DFS(1);  // idx  ��°�� ���� ä���
} 

void input(){
	cin >> N >> M;
}


int main() {	
 
 	input();
	solve(); 
 
	return 0;
} 
