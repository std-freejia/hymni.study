#include <iostream>
using namespace std;


/*   n과m (4)
중복 허용, 비내림차순  
1부터 n까지 자연수 중에서 m개를 고른 수열  
*/ 

int n, m;
int arr[10]; // 출력할 수열을 담는다.  
 
void go(int index, int start_num){  

	if(index == m){ // 수열 출력
		for(int i = 0; i < m; i++){
			printf("%d ", arr[i]);
		}
		cout << '\n';
		return; 
	} 
	
	for(int i = start_num; i <= n; i++){ // 선택 범위의 시작 숫자만 정해준다. 
		arr[index] = i; 
		go(index+1, i); // 반드시 i 보다 큰 수부터 다시 선택해야 하는게 아니다.(비내림차순)
	}

}

int main(void){
 
   	scanf("%d %d", &n, &m);
  	
  	go(0, 1); // 0번째 자리에 어떤 수를 넣을지 선택한다.  start는 선택범위의 시작숫자. 
  	
	return 0;
} 