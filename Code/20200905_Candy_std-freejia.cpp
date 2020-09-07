#include <iostream> 
#include <algorithm>
using namespace std;

// 사탕게임 BOJ 3085  (지아) 

int N;
char B[51][51];
int max_num;


void swap(int i, int j, int d_flag){  //  d_flag 1은 아래와 교환, 0은 오른쪽과 교환

	char c = B[i][j];
	
	if(d_flag){ // 아래와 교환  
		B[i][j] = B[i+1][j];
		B[i+1][j] = c; 
		
	}else { // 오른쪽과 교환  
		B[i][j] = B[i][j+1];
		B[i][j+1] = c; 
	}
}


void check(int i, int j, int d_flag){  // 교환, 가로확인, 세로확인, 재교환.  

	swap(i, j, d_flag); // 교환   
	
	int cnt = 1;
		
	// 모든 행의 가로 확인 
	for(int x = 0; x < N; x++){
	
		cnt = 1;
		for(int y = 0; y < N-1; y++){
		
		  	if(B[x][y] == B[x][y+1]){
		  		cnt++;
		  		max_num = max(max_num, cnt); // 갱신된 cnt 저장 
			}else{
				cnt = 1;
			}
		}
	}
	
	
	// 모든 열의 세로 확인 
	for(int x = 0; x < N; x++){
	
		cnt = 1;
		for(int y = 0; y < N-1; y++){
		  	if(B[y][x] == B[y+1][x]){
		  		cnt++;
		  		max_num = max(max_num, cnt); // 갱신된 cnt 저장 
			}else{
				cnt = 1;
			}
		}
	}

	swap(i, j, d_flag); // 제자리 돌려놓기  

} 

int main(void){
 
	cin >> N;
 
 	for(int i = 0; i < N; i++){
	  	for(int j = 0; j < N; j++){
			cin >> B[i][j];
		}	
	} // 입력받음  
 
	
	
	for(int i = 0; i < N; i++){ // 탐색  
	
	  	for(int j = 0; j < N; j++){
	  	
	 		if(j+1 < N){ // 오른쪽과 교환 가능  
				check(i, j, 0);
			}
			
			if(i+1 < N){ // 아래와 교환 가능 
                check(i, j, 1);
			}
		}	
	} 
	
	cout << max_num;	
	
	return 0;	
}
