#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// 테트로미노  (BOJ 14500) 지아  

int N, M;
int B[501][501]; 
int ans;
int i, j, a, b;

int main(void){
 
	cin >> N >> M; // 세로, 가로  

	int sum=0;
	
	
	// 입력받기
	for(i=1; i <= N; i++){ // 행 (세로)
	
		for(j=1; j <= M; j++){ // 열 (가로)
		 	cin >> B[i][j];
		} 
	}
	 
	
	for(i=1; i <= N; i++){ // 행 (세로) 
		
		for(j=1; j <= M; j++){ // 열 (가로) 
			
			if(j+3 <= M){ //   1x4 
				sum = B[i][j] + B[i][j+1] + B[i][j+2] + B[i][j+3];
				ans = max(ans, sum);
			}
			
			if(i+3 <= N){ //   4x1
				sum = B[i][j] + B[i+1][j] + B[i+2][j] + B[i+3][j];
				ans = max(ans, sum);
			}
			
			if(j+1 <= M && i+1 <= N){ // 2x2 네모  
				sum = B[i][j] + B[i+1][j] + B[i][j+1] + B[i+1][j+1];
				ans = max(ans, sum);
			}
			
			
			// 세로2 가로3 내부에서 
			if(i+1 <= N && j+2 <= M){
			
				int six_sum = 0;
				
				for(a=i; a <= (i+1); a++){
					for(b=j; b <= (j+2); b++){
						six_sum += B[a][b];
					}
				}
				
				sum = six_sum - (B[i+1][j] + B[i+1][j+2]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i][j] + B[i][j+2]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i][j] + B[i+1][j+2]);
				ans = max(ans, sum);

				sum = six_sum - (B[i+1][j] + B[i][j+2]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i][j+1] + B[i][j+2]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i][j] + B[i][j+1]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i+1][j] + B[i+1][j+1]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i+1][j+1] + B[i+1][j+2]);
				ans = max(ans, sum);
			} 
			
			// 세로3 가로2 내부에서 
			if(i+2 <= N && j+1 <= M){
			
				int six_sum = 0;
				
				for(a=i; a <= (i+2); a++){
					for(b=j; b <= (j+1); b++){
						six_sum += B[a][b];
					}
				}
				
				sum = six_sum - (B[i][j+1] + B[i+1][j+1]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i][j] + B[i+1][j]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i+1][j] + B[i+2][j]);
				ans = max(ans, sum);

				sum = six_sum - (B[i+1][j+1] + B[i+2][j+1]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i][j+1] + B[i+2][j+1]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i][j] + B[i+2][j]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i][j] + B[i+2][j+1]);
				ans = max(ans, sum);
				
				sum = six_sum - (B[i+2][j] + B[i][j+1]);
				ans = max(ans, sum);
			} 	
		}
	}
	
	cout << ans;

	return 0;
	
}
