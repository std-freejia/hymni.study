#include <iostream> 
using namespace std;

// ������ ��  

int N;
int D[1001][11]; // �ڸ���, ������ ����  

void solve(){

	int i=0, j=0, x=0;
	
	for(i=0; i <= 9; i++){
		D[1][i] = 1;
	}

	for(i = 2; i <= N; i++){ // �ڸ� �� ��ŭ �ݺ�  
		
		for(j = 0; j <= 9; j++){ // ������ ���ڰ� j �� ���,  
		
			for(x = 0; x <= j; x++){ // i-1 �ڸ����� 0���� j ���� �� �� �ִ�.  (������ ���ڰ� j�ϱ� �� ���ڸ��� 0���� j) 
				D[i][j] += D[i-1][x];
			}
			D[i][j] %= 10007;
		}
	}
} 

void input(){

	cin >> N ; // �ڸ���  
}


int main() {	
 
 	input();
	solve(); 
	
	int answer = 0;
	
	for(int i=0; i <= 9; i++){ // N�ڸ����� ������ �ڸ� ���ڰ� i �� ������  
		answer += D[N][i];
	}
	
	cout << answer % 10007;
	
	return 0;
} 
