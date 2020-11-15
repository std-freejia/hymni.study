#include <iostream> 
using namespace std;

// 오르막 수  

int N;
int D[1001][11]; // 자리수, 마지막 숫자  

void solve(){

	int i=0, j=0, x=0;
	
	for(i=0; i <= 9; i++){
		D[1][i] = 1;
	}

	for(i = 2; i <= N; i++){ // 자리 수 만큼 반복  
		
		for(j = 0; j <= 9; j++){ // 마지막 숫자가 j 인 경우,  
		
			for(x = 0; x <= j; x++){ // i-1 자리에는 0부터 j 까지 올 수 있다.  (마지막 숫자가 j니까 그 앞자리는 0부터 j) 
				D[i][j] += D[i-1][x];
			}
			D[i][j] %= 10007;
		}
	}
} 

void input(){

	cin >> N ; // 자리수  
}


int main() {	
 
 	input();
	solve(); 
	
	int answer = 0;
	
	for(int i=0; i <= 9; i++){ // N자리수의 마지막 자리 숫자가 i 인 가지수  
		answer += D[N][i];
	}
	
	cout << answer % 10007;
	
	return 0;
} 
