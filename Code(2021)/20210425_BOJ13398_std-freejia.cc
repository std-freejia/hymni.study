#include <iostream>
#include <algorithm>
using namespace std;

int n, num;
int a[100001];
int dp[100001][2];
int answer;

// 13398번 (연속합2)

int main()
{
 	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> a[i];
     }

	dp[0][0] = a[0];
	dp[0][1] = a[0];

	answer = max(dp[0][0], dp[0][1]);
	
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(0, dp[i - 1][0]) + a[i];
		dp[i][1] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
		answer = max(max(dp[i][0],dp[i][1]), answer);
	}

	cout << answer;
    
    return 0;
}