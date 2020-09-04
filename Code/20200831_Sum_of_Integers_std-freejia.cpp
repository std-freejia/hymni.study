#include <iostream> 
using namespace std;

// 부분수열의 합  1182 (지아)  

int N, S, answer;
int A[21]; 

void brute(int idx, int sum, int member_num){

	if(idx == N){
		if(sum == S && member_num > 0){ // 합이 S이며 공집합이 아니어야 함  
			answer++;
		}
		return;
	}
	
	brute(idx+1, sum+A[idx], member_num+1); // 현재 위치의 숫자를 집합에 포함
	brute(idx+1, sum, member_num); // 집합에 미포함  
}

int main(void){

	cin >> N >> S;

 	for(int i = 0; i < N; i++){
 		scanf("%d", &A[i]); // 수열 채우기  
	}  // 입력받기 끝  
 
 	brute(0, 0, 0);
	
	cout << answer;
	
	return 0;	
}
