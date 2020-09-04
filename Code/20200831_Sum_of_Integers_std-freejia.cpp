#include <iostream> 
using namespace std;

// �κм����� ��  1182 (����)  

int N, S, answer;
int A[21]; 

void brute(int idx, int sum, int member_num){

	if(idx == N){
		if(sum == S && member_num > 0){ // ���� S�̸� �������� �ƴϾ�� ��  
			answer++;
		}
		return;
	}
	
	brute(idx+1, sum+A[idx], member_num+1); // ���� ��ġ�� ���ڸ� ���տ� ����
	brute(idx+1, sum, member_num); // ���տ� ������  
}

int main(void){

	cin >> N >> S;

 	for(int i = 0; i < N; i++){
 		scanf("%d", &A[i]); // ���� ä���  
	}  // �Է¹ޱ� ��  
 
 	brute(0, 0, 0);
	
	cout << answer;
	
	return 0;	
}
