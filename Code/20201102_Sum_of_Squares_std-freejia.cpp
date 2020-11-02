#include <iostream>
#include <algorithm> 
using namespace std;
 
// �������� �� Sum_of_Squares  (BOJ 1699)  �������.   
 
int N;
int D[100001];

int main() {	
 
 	cin >> N;

 	for(int i = 1; i <= N; i++){
 		D[i] = i;
 		
 		for(int j = 1; j*j <= i; j++){ // i���� ���� ������  
 			D[i] = min(D[i] , D[i - j*j] + 1); 
		}
	} 
 	cout << D[N];
 	
	return 0;
} 
