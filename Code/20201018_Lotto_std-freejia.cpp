#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

void lotto(vector<int> &A, int N){

	int ch[50] = {0, };  // 전부 0초기화 
	
	// 6부터 N 직전까지만 1로 변경 ( N개중에서 6개만 선택하려면, 선택 안할 숫자만큼 1로 변경됨 ) 
	for(int i = 6; i < N ; i++){
		ch[i] = 1;
	}
    
    // N이 7 일 때, 위의 for문 수행 후 ch 배열은  0 0 0 0 0 0 1 .. ... 0 로 채워져 있다.  
   // 7-6은 1이니까. 1개만 1로 표시되고 do while을 시작한다. 
    
	do{
	
		for(int i = 0; i < N; i++){
			if(!ch[i]) cout << A[i] << ' ';
		}
		cout << '\n';
	}while(next_permutation(ch, ch+N));
	
    // next_permu() 함수를 통해 ch 배열은 
    // 0 0 0 0 0 0 1 ..
    // 0 0 0 0 0 1 0 ..
    // 0 0 0 0 1 0 0 .. 이렇게 한칸씩 1표시 한것들이 앞으로 온다. 
    	
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
