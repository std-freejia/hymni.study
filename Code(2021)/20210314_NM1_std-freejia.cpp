#include <iostream>
using namespace std;
 
int N, M;
int check[10]; // 중복 방지  
int answer[10]; // m 개의 숫자를 채울 배열  

void permu(int idx){ // 'idx' 번째에 어떤 수를 놓을지 고른다. 

	if(idx > M){ // 이미 M개를 골랐으니까, M번째를 초과하는 순간 종료. 
	
		// 수열 출력 
		for(int p = 1; p <= M; p++){
			cout << answer[p] << ' ';
		}
		cout << '\n';
		
		return; 
	}
	
	for(int i = 1; i <= N; i++){ 
	
		if(check[i]) continue; // 이미 선택된 수는 지나간다 
		
		check[i] = 1; // 선택 함
		answer[idx] = i; // idx 자리에 숫자 i 배치 
		
		permu(idx+1); // 다음 자리의 숫자 고르러 재귀 		 
		
		check[i] = 0; // 선택 안함  
	}
}

int main(void){

	//freopen("input.txt", "rt", stdin);

	cin >> N >> M;
	
	permu(1);
	
	return 0;	
}