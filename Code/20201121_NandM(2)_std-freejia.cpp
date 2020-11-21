#include <iostream> 
using namespace std;
  
int N, M; // �ڿ��� N, M 
bool check[10];
int answer[10];

void DFS(int idx, int start){

	if(idx > M){ // M �� ���� �Ϸ�. 
	
		for(int i = 1; i <= M; i++){
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for(int i = start; i <= N; i++){ // start ���� N ���� idx �ڸ��� ��ġ 
		if(check[i]) continue; // �̹� ������ ���ڴ� �������� 
		
		check[i] = true;
		answer[idx] = i; // idx �ڸ��� ���� i ���� 
		DFS(idx+1, i+1); // idx+1�ڸ��� ���ڸ� �����ϱ� ���� ���. ���� ���ڴ� i+1 ����. 
		check[i] = false; 
	}
	
}

void solve(){
	DFS(1, 1);  // idx  ��°�� ���� ä��µ�, ������ '���� ����' start
} 

void input(){
 	cin >> N >> M;
}


int main() {	
 
 	input();
	solve(); 
 
	return 0;
} 
