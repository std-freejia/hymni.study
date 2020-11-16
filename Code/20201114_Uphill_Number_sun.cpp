/*
1. DP
2. n자리 오르막 수로 생성할 수 있는 n+1자리 오르막 수는
   n자리 오르막 수의 끝자리로 결정
3. 0으로 끝나면 뒤에 0~9 붙일 수 있고
   1로 끝나면 뒤에 1~9 붙일 수 있고
   ......
4. num_n(x로 끝) = num_n-1(x로 끝) + num_n(x-1로 끝)
5. N = 1,2,3......때 0~9로 끝나는 오르막 수의 개수의 
   합이 오르막 수의 총개수
*/

#include <iostream>

using namespace std;

const int MAX = 1000;
int nums[MAX + 1][10] = {0};  // 0~9로 끝나는 오르막 수의 개수

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop
    int result = 0;
    
    cin>>N;
    
    // N = 1 때 0~9로 끝나는 오르막 수의 개수가 모두 1
    for(i=0; i<10; i++)
    {
        nums[1][i] = 1;
    }
    
    // num_n(x로 끝) = num_n-1(x로 끝) + num_n(x-1로 끝)
    for(i=2; i<=N; i++)
    {
        nums[i][0] = 1;
        
        for(j=1; j<10; j++)
        {
            nums[i][j] = (nums[i][j-1] + nums[i-1][j]) % 10007;
        }
    }
    
    // 오르막 수의 총개수
    for(i=0; i<10; i++)
    {
        result += nums[N][i];
        result %= 10007;
    }
    
    cout<<result;
    
    return 0;
}
