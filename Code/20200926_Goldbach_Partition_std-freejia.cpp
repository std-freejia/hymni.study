#include <iostream>
#include <algorithm> 
#define MAX 1000000
using namespace std;


// 골드바흐 파티션 ( 지아 ) 
 
int TC;
int p[MAX+1]; // 소수 저장  (소수만 1로 표시) 

void Prime(){
	
	p[0] = p[1] = 0; // 0과 1은 소수가 아니다.  나머지 숫자들은 일단 전부 소수라고 생각한다.  
	
	for(int i = 2; i <= MAX; i++){ // 자기 자신을 저장 
		p[i] = i;
	} 
	
	for(int i = 2; i*i <= MAX; i++){ // 소수의 배수들를 0으로 지운다.  
	
		if(p[i] == i){
			
			for(int j = i*i; j <= MAX; j += i ){ // i만큼 건너 뛰어서 배수 찾아서 0으로 바꾼다. 
				p[j] = 0; 
			}
		} 
	}
}

int main(void){
 
	Prime(); // 에라토스테네스의 체 
	
	cin >> TC;
	
	while(TC--){
	
		int N = 0;
		cin >> N;
		int cnt = 0;
		
		for(int i = 2; i < N; i++){ // 소수가 현재 입력 수보다 작은 동안.
			
			if((p[N-i] + p[i]) == N){ // 소수 끼리의 합으로 N을 표현할 수 있는지. 
			
				cnt++;
				
				if(N-i == i){ // 10 = 5+5; 의 경우를 고려. 
					cnt++; 
				}
			}
		}
		
		printf("%d\n", cnt/2);
		 
	}
	
	return 0;
} 
