#include <iostream> 
using namespace std;

int N;
int D[100001][3];

int main() {	
 
 	cin >> N ; // �츮�� ���� ����  
	
     // 0 : �ƿ� 1�࿡�� �� ���´�.  1: ���ʿ� ���´�.  2:�����ʿ� ���´�.   
    D[1][0] = D[1][1] = D[1][2] = 1;  
 	
 	for(int i = 2; i <= N; i++){
 		D[i][0] =  ( D[i-1][0] + D[i-1][1] + D[i-1][2] ) % 9901; 
 		D[i][1] =  ( D[i-1][0] + + D[i-1][2] ) % 9901; 
 		D[i][2] =  ( D[i-1][0] + + D[i-1][1] ) % 9901; 
	}
	
	int sum = D[N][0] + D[N][1] + D[N][2]; 
	cout << sum % 9901;
	
	return 0;
} 
