#include <stdio.h>

//BAEKJOON 10971, 200911 외판원 순회2(브루트포스), LDH

int n, arr[12][12];
bool check[12];
int ans[12];
int minVal = 2e9;	//2*10^9, int의 무한대를 나타낼때 사용

int tsp(int, int);

int main(int argc, char* argv[], char* env[])
{
    scanf("%d", &n);
	
    for(int i = 1; i <= n; i++)
	{
        for(int j = 1; j <= n; j++)
		{
            scanf("%d", &arr[i][j]);
		}
	}
	
    tsp(0, 1);	//재귀함수 시작
	
    printf("%d", minVal);
	
    return 0;
}

int tsp(int cnt, int cur)
{
    if(cnt == n)
	{
        int temp = 0;
		int i = 0;
		
        for(i = 0; i < n-1; i++)
		{
            temp += arr[ans[i]][ans[i+1]];
		}
		
        if(arr[ans[i]][ans[0]] != 0)
		{
            temp += arr[ans[i]][ans[0]];
		}
        else
		{
            return 0;
		}
		
        minVal = minVal > temp?temp:minVal;
		
        return 0;
    }
    
    for(int i = 1; i <= n; i++)
	{
        if(!check[i] && arr[cur][i] != 0)
		{
            check[i] = true;
            ans[cnt] = i;
            tsp(cnt+1, i);
            check[i] = false;
        }
    }
	
	return 0;
}