#include <iostream> 
using namespace std;
  
int N, M; // 자연수 N, M 
bool check[10];
int answer[10];

void DFS(int idx, int start){

	if(idx > M){ // M 개 선택 완료. 
	
		for(int i = 1; i <= M; i++){
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for(int i = start; i <= N; i++){ // start 부터 N 까지 idx 자리에 배치 
		if(check[i]) continue; // 이미 선택한 숫자는 지나간다 
		
		check[i] = true;
		answer[idx] = i; // idx 자리에 숫자 i 선택 
		DFS(idx+1, i+1); // idx+1자리의 숫자를 선택하기 위한 재귀. 시작 숫자는 i+1 부터. 
		check[i] = false; 
	}
	
}

void solve(){
	DFS(1, 1);  // idx  번째의 수를 채우는데, 범위의 '시작 숫자' start
} 

void input(){
 	cin >> N >> M;
}


int main() {	
 
 	input();
	solve(); 
 
	return 0;
} 
