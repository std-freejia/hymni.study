#include <iostream> 
using namespace std;
 
// 타일채우기 BOJ 2133  (지아)  
 
int N;
int A[31];

/* A의 짝수 인덱스만 다룬다. 홀수 인덱스는 2x1 타일로는 채울 수 없기 때문. 
A[0] = 1
A[2] = 3
A[4] = A[2]*3 + A[0]*2; 
A[6] = A[4]*3 + A[2]*2 + A[0]*2;
 
A[4] 부터는 자신의 인덱스보다 4이상 차이 나는 값에 x2 한 값을 더해줘야 한다.  

 https://kibbomi.tistory.com/71 포스팅 보고 배움  
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
