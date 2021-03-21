#include <iostream>
#include <algorithm> 
using namespace std;
 
// n과 m  (5)

int N, M; // 1부터 N까지의 자연수 중에서 M개를 고른 수열.  
int arr[10]; // 입력받은 수열 저장.
int ch[10]; // 중복을 허용하지 않으니까, 체크 배열이 필요하다.
int answer[10];

void go(int index){
	
	if(index == M){
		for(int i = 0; i < M; i++){
			printf("%d ", answer[i]);
		}
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < N; i++){
		if(ch[i]) continue;
		
		ch[i] = 1;
		answer[index] = arr[i];
		go(index+1);
		ch[i] = 0;
	}
}
 
int main(void){

	cin >> N >> M;
 	
 	for(int i = 0; i < N; i++){
 		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+N);
	
 	go(0);

	return 0;
}