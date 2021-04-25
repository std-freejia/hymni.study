#include <iostream> 
using namespace std;
 
 
// 2133번 (타일채우기) 
 
int N;
int A[31];
 
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