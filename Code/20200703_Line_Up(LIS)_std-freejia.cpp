#include <stdio.h>
#include <algorithm>
using namespace std;
 
// 줄세우기  (백준2631) by std-freejia 

 
int a[1001];  // 입력받은 수열  
int dp[1001]; // i가 마지막 수인 수열의 LIS 저장  
 
int main() {

	int i, j, n, ans = 0;
	
    scanf("%d",&n);
    
    for(i=1; i<=n; i++){
		scanf("%d",&a[i]); 
    }// 입력받기 끝 
    
    for(i=1; i<=n; i++){
    
        for(j=0; j<i; j++){
		
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j]+1);
                
        	ans = max(ans, dp[i]); // 갱신  
        }
    }
    
    printf("%d", n - ans); // 이동해야 할 학생 수  
    
	return 0;
}
 
