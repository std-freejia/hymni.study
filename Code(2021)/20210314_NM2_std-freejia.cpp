#include <iostream>
#include <algorithm> 
using namespace std;

// N과 M (2)  

int N, M;
bool check[10];
int answer[10];

void go(int index, int start){

	if(index == M){
		// 수열 출력 
		for(int i = 0; i < M; i++){
			cout << answer[i] << ' ';
		} 
		cout << '\n';
		return;
	}
	
	for(int i = start; i <= N; i++){
		if(check[i]) continue; // 이미 선택된 숫자라면 지나간다. 
		
		check[i] = true;
		answer[index] = i; // index 자리에 i를 선택한다. 
		go(index+1, i+1); // index+1 자리에 (==다음 자리)숫자를 고르기 위해 재귀 호출.
		check[i] = false; 
	}

}
 
int main(void){

 	scanf("%d %d", &N, &M);
 
	go(0, 1); // 0번째를 채우자.  
	 
	return 0;
} 