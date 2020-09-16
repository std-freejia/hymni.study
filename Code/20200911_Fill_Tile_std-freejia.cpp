#include <iostream> 
using namespace std;
 
// Ÿ��ä��� BOJ 2133  (����)  
 
int N;
int A[31];

/* A�� ¦�� �ε����� �ٷ��. Ȧ�� �ε����� 2x1 Ÿ�Ϸδ� ä�� �� ���� ����. 
A[0] = 1
A[2] = 3
A[4] = A[2]*3 + A[0]*2; 
A[6] = A[4]*3 + A[2]*2 + A[0]*2;
 
A[4] ���ʹ� �ڽ��� �ε������� 4�̻� ���� ���� ���� x2 �� ���� ������� �Ѵ�.  

 https://kibbomi.tistory.com/71 ������ ���� ���  
*/
 
int main(void){
 
	cin >> N;
	A[0] = 1;
	A[2] = 3;
	
	for(int i = 4; i <= N; i += 2){
		A[i] = A[i-2] * 3;
		
		for(int j = 4; j <= i; j += 2){
			A[i] += A[i-j] * 2;
		}
	}
	
	cout << A[N];
	
	return 0;
} 
