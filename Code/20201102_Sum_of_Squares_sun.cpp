/*
1. DP + 브루트포스
2. n = i의 제곱 + (n - i의 제곱)
3. result[n] = 1 + result[n - i의 제곱]
4. 1 <= i <= n의 제곱근
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int sqr_num[MAX_N + 1] = {0};  // 0~100000의 최소 제곱수 항 개수 저장

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    int item = 0;
    
    cin>>N;
    
    // sqr_num[0] = 0
    // sqr_num[1]부터 계산
    for(int i=1; i<=N; i++)
    {
        item = (int)sqrt(i);  // item : 사용 가능한 최대 제곱근
        sqr_num[i] = sqr_num[i - item * item] + 1;
        
        // 제곱근 줄이면서 최소 개수 찾기
        for(int j=item-1; j>0; j--)
        {
            sqr_num[i] = min(sqr_num[i], sqr_num[i - j * j] + 1);
        }
    }
    
    cout<<sqr_num[N];
    
    return 0;
}
