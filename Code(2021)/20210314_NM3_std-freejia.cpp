#include <iostream>
#include <algorithm> 
using namespace std;
 
/*  n과 m (3)
중복 허용
1부터 n까지 자연수 중에서 m개를 고른 수열  
*/ 

int n, m;
int arr[10]; // 출력할 수열을 담는다.  
 
void go(int index){  // index 0부터 m-1 까지 어떤 수로 채울지 선택하는 함수  

	if(index == m){ // index m-1까지 모든 수를 골랐으니까 수열 출력 
		
		for(int i = 0; i < m; i++){ // 수열 출력
			printf("%d ", arr[i]);
		}
		cout << '\n';		
		return; 
	} 
	
	for(int i = 1; i <= n; i++){ // 1부터 n까지 수를 '중복 허용'하여 선택
		arr[index] = i;
		go(index+1); // 다음 자리 숫자를 고르러 재귀호출 
	}

}

int main(void){
 
   	scanf("%d %d", &n, &m);
  	
  	go(0); // 0번째 자리에 어떤 수를 넣을지 선택한다.  
  	
	return 0;
} 