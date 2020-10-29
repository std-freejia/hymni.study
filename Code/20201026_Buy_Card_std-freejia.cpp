#include <iostream>
#include <algorithm> 
using namespace std;

// 카드 구매하기 (BOJ 11052)  

int N;
int P[10001];
int D[1001];

void process_stdin() { // 입력받기  
 
 	cin >> N;
 	
 	for(int i = 1; i <= N; i++){
 		scanf("%d", &P[i]);
	}
}

int main() {	

	process_stdin();
   
 	D[1] = P[1];
 	
 	for(int i = 2; i <= N; i++){
	 	for(int j = 1; j <= i; j++){
	 		D[i] = max(D[i-j] + P[j], D[i]);
		} 	
	}
 
 	cout << D[N];
 
	return 0;
}
