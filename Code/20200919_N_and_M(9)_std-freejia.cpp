#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// N과M(9)  BOJ 15663  (지아)  
 
int N, M;
vector<int> v;
int answer[10];
int check[10]; 

void permu(int idx){ // 채울 자리의 위치idx 

	if(idx == M){ // 수열 출력
	
		for(int i = 0; i < M; i++){
			 cout << answer[i] << ' ';
		} 
		cout << '\n';
		
		return;
	}
	
	int before = -1; // 이전에 고른 값을 기억한다  
	
	for(int i = 0; i < N; i++){
 
 		if(check[i] > 0 && before != v[i]){ // 이전 값과 다른 값을 골라야 한다.  
 			
	 		check[i] -= 1;
			answer[idx] = v[i];  
			before = v[i]; // 현재 고른값 기억. 
									           
			permu(idx+1); // 다음 자리 숫자 채우기 
			
	 		check[i] +=1 ;
		}
 		
	}
} 

int main(void){

	cin >> N >> M;

	int num = 0;

	for(int i = 0; i < N; i++){
		cin >> num;
		
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < N; i++){ // 각 숫자의 개수를 check 배열에 저장  
		int idx = find(v.begin(), v.end(), v[i])-v.begin();
		check[idx]++;	 
	}
	
	// find() : v[i]의 '원소의 위치'를 iterator로 반환한다.  
	
	permu(0);
	
	return 0;	
}
