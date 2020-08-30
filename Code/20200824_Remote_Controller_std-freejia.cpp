#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX_CH 1000000
using namespace std;

// ������ (BOJ 1107)  

int N, M; 
bool broken[11]; //0~9 ��ư   true�� ����  
int min_cnt = 2147000000;
 
int check_broken(int ch){ 

	int cnt = 0; // ��ư�� �������� Ƚ��  
	
	if(ch == 0){
		if(broken[0]) return 0; // �� ����  
		else return 1;
	}
	
	while(ch > 0){
		if(broken[ch % 10]) return 0; // �� ���� 		
		ch /= 10;
		cnt++;
	}
	
	return cnt;
}

int main(void){

	freopen("input.txt", "rt", stdin);
 	
 	cin >> N >> M; // ��ǥ ä��, ���� ��ư����  
	
	int ch = 0;
	
	for(int i = 0; i < M; i++){
		cin >> ch;
		broken[ch] = true; // ������ true�� ǥ��  
	} 
	
	// ��ǥ ä�η� '���ڸ�' ������ �̵��ϴ� Ƚ�� 
	int answer = abs(N-100); // ���� ä��100���� ����  
	
	// ��ǥ ä�η� ���ڿ� +/- �Բ� ������ �̵��ϴ� Ƚ��  
	for(int i = 0; i <= MAX_CH; i++){
	
		ch = i;
		
		// �����ư Ȯ�� ��, �������� ��ư Ƚ��  
		int cnt_bt = check_broken(ch);	 
		// ���ڸ� ������ �̵�  
		int num_press = abs(N-ch);
		
		if(cnt_bt > 0){
			answer = min(answer, num_press + cnt_bt);
		}
	} 
	
 	cout << answer;
	
	return 0;
	
}
