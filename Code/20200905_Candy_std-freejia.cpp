#include <iostream> 
#include <algorithm>
using namespace std;

// �������� BOJ 3085  (����) 

int N;
char B[51][51];
int max_num;


void swap(int i, int j, int d_flag){  //  d_flag 1�� �Ʒ��� ��ȯ, 0�� �����ʰ� ��ȯ

	char c = B[i][j];
	
	if(d_flag){ // �Ʒ��� ��ȯ  
		B[i][j] = B[i+1][j];
		B[i+1][j] = c; 
		
	}else { // �����ʰ� ��ȯ  
		B[i][j] = B[i][j+1];
		B[i][j+1] = c; 
	}
}


void check(int i, int j, int d_flag){  // ��ȯ, ����Ȯ��, ����Ȯ��, �米ȯ.  

	swap(i, j, d_flag); // ��ȯ   
	
	int cnt = 1;
		
	// ��� ���� ���� Ȯ�� 
	for(int x = 0; x < N; x++){
	
		cnt = 1;
		for(int y = 0; y < N-1; y++){
		
		  	if(B[x][y] == B[x][y+1]){
		  		cnt++;
		  		max_num = max(max_num, cnt); // ���ŵ� cnt ���� 
			}else{
				cnt = 1;
			}
		}
	}
	
	
	// ��� ���� ���� Ȯ�� 
	for(int x = 0; x < N; x++){
	
		cnt = 1;
		for(int y = 0; y < N-1; y++){
		  	if(B[y][x] == B[y+1][x]){
		  		cnt++;
		  		max_num = max(max_num, cnt); // ���ŵ� cnt ���� 
			}else{
				cnt = 1;
			}
		}
	}

	swap(i, j, d_flag); // ���ڸ� ��������  

} 

int main(void){
 
	cin >> N;
 
 	for(int i = 0; i < N; i++){
	  	for(int j = 0; j < N; j++){
			cin >> B[i][j];
		}	
	} // �Է¹���  
 
	
	
	for(int i = 0; i < N; i++){ // Ž��  
	
	  	for(int j = 0; j < N; j++){
	  	
	 		if(j+1 < N){ // �����ʰ� ��ȯ ����  
				check(i, j, 0);
			}
			
			if(i+1 < N){ // �Ʒ��� ��ȯ ���� 
                check(i, j, 1);
			}
		}	
	} 
	
	cout << max_num;	
	
	return 0;	
}
