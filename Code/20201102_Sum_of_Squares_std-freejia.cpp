#include <iostream>
#include <algorithm> 
using namespace std;
 
// Á¦°ö¼öÀÇ ÇÕ Sum_of_Squares  (BOJ 1699)  ¾î·Á¿ü´Ù.   
 
int N;
int D[100001];

int main() {	
 
 	cin >> N;

 	for(int i = 1; i <= N; i++){
 		D[i] = i;
 		
 		for(int j = 1; j*j <= i; j++){ // iº¸´Ù ÀÛÀº Á¦°ö¼ö  
 			D[i] = min(D[i] , D[i - j*j] + 1); 
		}
	} 
 	cout << D[N];
 	
	return 0;
} 
