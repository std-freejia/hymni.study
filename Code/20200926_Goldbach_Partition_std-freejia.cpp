#include <iostream>
#include <algorithm> 
#define MAX 1000000
using namespace std;


// ������ ��Ƽ�� ( ���� ) 
 
int TC;
int p[MAX+1]; // �Ҽ� ����  (�Ҽ��� 1�� ǥ��) 

void Prime(){
	
	p[0] = p[1] = 0; // 0�� 1�� �Ҽ��� �ƴϴ�.  ������ ���ڵ��� �ϴ� ���� �Ҽ���� �����Ѵ�.  
	
	for(int i = 2; i <= MAX; i++){ // �ڱ� �ڽ��� ���� 
		p[i] = i;
	} 
	
	for(int i = 2; i*i <= MAX; i++){ // �Ҽ��� ����鸦 0���� �����.  
	
		if(p[i] == i){
			
			for(int j = i*i; j <= MAX; j += i ){ // i��ŭ �ǳ� �پ ��� ã�Ƽ� 0���� �ٲ۴�. 
				p[j] = 0; 
			}
		} 
	}
}

int main(void){
 
	Prime(); // �����佺�׳׽��� ü 
	
	cin >> TC;
	
	while(TC--){
	
		int N = 0;
		cin >> N;
		int cnt = 0;
		
		for(int i = 2; i < N; i++){ // �Ҽ��� ���� �Է� ������ ���� ����.
			
			if((p[N-i] + p[i]) == N){ // �Ҽ� ������ ������ N�� ǥ���� �� �ִ���. 
			
				cnt++;
				
				if(N-i == i){ // 10 = 5+5; �� ��츦 ���. 
					cnt++; 
				}
			}
		}
		
		printf("%d\n", cnt/2);
		 
	}
	
	return 0;
} 
