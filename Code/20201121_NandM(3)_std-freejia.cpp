#include <iostream> 
using namespace std;
  
int N, M; // 자연수 N, M 
int answer[10];

void DFS(int idx){
 
 	if(idx > M){ // M개 선택 완료
		for(int i = 1; i <= M; i++){
			cout << answer[i] << ' ';
		} 
		cout << '\n';
		return;
	}
	
	for(int i = 1; i <= N; i++){ // 중복된 숫자 선택해도 괜찮음 
		
		answer[idx] = i;
		DFS(idx+1);
	}
	
}

void solve(){
	DFS(1);  // idx  번째의 수를 채운다
} 

void input(){
	cin >> N >> M;
}


int main() {	
 
 	input();
	solve(); 
 
	return 0;
} 
