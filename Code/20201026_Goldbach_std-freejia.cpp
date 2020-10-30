#include <iostream>
#include <algorithm> 
#include <vector>
#define MAX 1000001
using namespace std;

int N;
vector<int> P(MAX, 1); // 처음에는 모든 수를 소수라고 1표시  

void get_prime(){

	P[1] = 0; 

	for(int i = 2; i*i <= MAX; i++){
	
		if(P[i] == 0) continue;
		for(int j = i*i; j <= MAX; j += i){ // 소수의 배수들을 지운다. 0표시  
			P[j] = 0;
		}	
	}
 	 
}

void check(int n){

	int a=0, b=0;
	bool answer = false;
	
	for(int i = 3; i <= n; i++){
		
		if(P[i] == 1 && P[n-i] == 1){ // 소수라면,  
			a = i, b = n-i; answer = true; break;
		}
	}

	if(answer){
		printf("%d = %d + %d\n", n, a, b); 
	}else{
		printf( "Goldbach's conjecture is wrong.\n");
	}
}
 

int main() {	
 
	get_prime(); // 소수 구하기 
	 
 	
 	while(EOF != scanf("%d", &N)){ // 입력 받기  
 	
 		if(N == 0) break;
 		
		check(N);
	}
 
	return 0;
} 
