#include <iostream>
#include <algorithm>  
using namespace std;

// ��� 14501  (����) 
 
int N;
int T[16];
int P[16]; 
int max_sum;

void advice(int day, int sum){

	if(N == day){ // ���� 
		max_sum = max(max_sum, sum);
		return;
	}
	
	if(N < day){ // ���� ��¥ �ʰ�  
		return;
	}
	
	advice(day + T[day], sum + P[day]); // ���� ����Ѵ�  
	advice(day + 1, sum);  // ���� ��� ���ϰ� �������� ��������  
}

int main(void){
 
	cin >> N;

 	for(int i = 0; i < N; i++){
 		scanf("%d %d", &T[i], &P[i]);
	}  // �Է¹ޱ� ��  
 
	advice(0, 0);
	
	cout << max_sum;
	
	return 0;	
}
