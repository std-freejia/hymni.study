#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
  
int N, M; // 자연수 N, M 
int check[10];
int answer[10];

void DFS(int idx){

	if(idx > M){ // M개 골랐다.
		for(int i = 1; i <= M; i++){
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;  
	}
	
	for(int i = 1; i <= N; i++){
		if(check[i]) continue;
		
		check[i] = 1; // 선택 한다  
		answer[idx] = i; // 자리 idx에 숫자 i 배치  
		DFS(idx+1);
		check[i] = 0; // 선택 안한다  
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
