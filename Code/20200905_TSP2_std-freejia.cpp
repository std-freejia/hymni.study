#include <iostream> 
#include <algorithm>
using namespace std;

// ���ǿ� ��ȸ 2  (10971)  

int N;
int A[11];
int W[11][11]; 


int main(void){
	
	int answer = 2147000000;
	
	cin >> N ;

	for(int j = 1; j <= N; j++){ // ���� ��ȣ ����  (1���� N) 
 		A[j] = j;
	}  
		
 	for(int i = 1; i <= N; i++){
 		for(int j = 1; j <= N; j++){
 			cin >> W[i][j];
		}  
	}  // �Է¹ޱ� ��  
 
 
	do{
	
		bool all_ch = true;
		int temp_sum = 0;
		int j = 1; 
		
		for(j = 1; j <= N-1; j++){  
			
 			if(W[A[j]][A[j+1]] > 0) {
 				temp_sum += W[A[j]][A[j+1]];
			}else{
				all_ch = false; 
				break; 
			}
		} 
		
		if(W[A[j]][A[1]]) temp_sum += W[A[j]][A[1]];
		else all_ch = false;
		
		if(all_ch) {
			answer = min(answer, temp_sum);
		}
		
	}while(next_permutation(A, A+N));

	
	cout << answer;
	
	return 0;	
}
