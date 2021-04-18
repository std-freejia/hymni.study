#include <iostream>
#include <algorithm>  
using namespace std;

// 14501번 퇴사  
 
int N;
int T[16];
int P[16]; 
int ch[16];
int max_sum;

void advice(int day, int sum){

	if(N == day){ // 종료 
		max_sum = max(max_sum, sum);
		return;
	}
	
	if(N < day){ // 제한 날짜 초과  
		return;
	}
	
	advice(day + T[day], sum + P[day]); // 오늘 상담한다  
	advice(day + 1, sum);  // 오늘 상담 안하고 다음날로 지나간다  
}

int main(void){
 
	cin >> N;

 	for(int i = 0; i < N; i++){
 		cin >> T[i] >> P[i];
	}  // 입력받기 끝  
 
	advice(0, 0); // 날짜를 0 부터 시작. 
	
	cout << max_sum;
	
	return 0;	
}