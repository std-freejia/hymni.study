#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
  
int N, M; // �ڿ��� N, M 
int check[10];
int answer[10];

void DFS(int idx){

	if(idx > M){ // M�� �����.
		for(int i = 1; i <= M; i++){
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;  
	}
	
	for(int i = 1; i <= N; i++){
		if(check[i]) continue;
		
		check[i] = 1; // ���� �Ѵ�  
		answer[idx] = i; // �ڸ� idx�� ���� i ��ġ  
		DFS(idx+1);
		check[i] = 0; // ���� ���Ѵ�  
	}	
}

void solve(){
	DFS(1);
} 

void input(){
	cin >> N >> M;
}


int main() {	
 
 	input();
	solve(); 

	return 0;
} 
