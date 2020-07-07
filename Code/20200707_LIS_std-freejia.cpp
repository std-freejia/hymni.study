#include <stdio.h>
#include <algorithm>
using namespace std;

// LIS (std-freejia)
// 참고 https://wootool.tistory.com/96 

int n, ans;
int a[1001];
int dp[1001];
 
int main() {

    scanf("%d",&n);
    
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    
    for(int i=1; i<=n; i++){
    
        for(int j=0; j<i; j++){
		
            if(a[i]>a[j])
                dp[i] = max(dp[i], dp[j]+1);
                
        	ans = max(ans, dp[i]);
        }
    }
    
    printf("%d",ans);
    return 0;
}
 