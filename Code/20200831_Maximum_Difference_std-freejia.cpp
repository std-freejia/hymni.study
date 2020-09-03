#include <iostream>
#include <cstdlib> // int abs(int)
#include <algorithm> //  next_permutation( )
using namespace std;

// ���̸� �ִ��  (����)  
 
int N;
int a[10];

int main(void){
 
	int max_value = 0;
	
	cin >> N;

 	for(int i = 0; i < N; i++){
 		scanf("%d", &a[i]);
	}  // �Է¹ޱ� ��  
	
	sort(a, a+N); // ������ �ϰ��� next_permutation() 
	
 	do{

 		int max_tmp = 0;
 		
 		for(int i = 0; i < N-1; i++){
 			max_tmp += abs(a[i]-a[i+1]);
		} 

		max_value = max(max_tmp, max_value);
		
	}while(next_permutation(a, a+N));
	
	cout << max_value;
	
	return 0;	
}
