#include <iostream>
#include <algorithm> 
#include <vector>
#define MAX 1000001
using namespace std;

int N;
vector<int> P(MAX, 1); // ó������ ��� ���� �Ҽ���� 1ǥ��  

void get_prime(){

	P[1] = 0; 

	for(int i = 2; i*i <= MAX; i++){
	
		if(P[i] == 0) continue;
		for(int j = i*i; j <= MAX; j += i){ // �Ҽ��� ������� �����. 0ǥ��  
			P[j] = 0;
		}	
	}
 	 
}

void check(int n){

	int a=0, b=0;
	bool answer = false;
	
	for(int i = 3; i <= n; i++){
		
		if(P[i] == 1 && P[n-i] == 1){ // �Ҽ����,  
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
 
	get_prime(); // �Ҽ� ���ϱ� 
	 
 	
 	while(EOF != scanf("%d", &N)){ // �Է� �ޱ�  
 	
 		if(N == 0) break;
 		
		check(N);
	}
 
	return 0;
} 
