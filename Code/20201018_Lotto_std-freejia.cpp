#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

void lotto(vector<int> &A, int N){

	int ch[50] = {0, };  // ���� 0�ʱ�ȭ 
	
	// 6���� N ���������� 1�� ���� ( N���߿��� 6���� �����Ϸ���, ���� ���� ���ڸ�ŭ 1�� ����� ) 
	for(int i = 6; i < N ; i++){
		ch[i] = 1;
	}
    
    // N�� 7 �� ��, ���� for�� ���� �� ch �迭��  0 0 0 0 0 0 1 .. ... 0 �� ä���� �ִ�.  
   // 7-6�� 1�̴ϱ�. 1���� 1�� ǥ�õǰ� do while�� �����Ѵ�. 
    
	do{
	
		for(int i = 0; i < N; i++){
			if(!ch[i]) cout << A[i] << ' ';
		}
		cout << '\n';
	}while(next_permutation(ch, ch+N));
	
    // next_permu() �Լ��� ���� ch �迭�� 
    // 0 0 0 0 0 0 1 ..
    // 0 0 0 0 0 1 0 ..
    // 0 0 0 0 1 0 0 .. �̷��� ��ĭ�� 1ǥ�� �Ѱ͵��� ������ �´�. 
    	
	cout << '\n';
	
	return;
}

int main(void){
 
	int k = 1;
    int N = 0;
	vector<int> A;
	
	while(1){
		
		scanf("%d", &N);
		if(N == 0) break;
		
		for(int i = 0; i < N; i++){
			int num = 0;
			cin >> num;
			A.push_back(num);
		}
		
		lotto(A, N);
		A.clear();
	} 

	return 0;	
}
