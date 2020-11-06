/*
1. nCm = n! / m!(n-m)!
2. k!의 i개수 = ∑ k/i^n
3. long long 형
*/

#include <iostream>
#include <algorithm>

using namespace std;

long long int cal_2_or_5(long long int num, int b);

int main(int argc, char* argv[], char* envs[])
{
    // 시간 초과 방지
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long int n = 0;
    long long int m = 0;
    long long int num_2 = 0;
    long long int num_5 = 0;

    cin >> n >> m;

    num_2 = cal_2_or_5(n, 2) - cal_2_or_5(m, 2) - cal_2_or_5(n - m, 2);
    num_5 = cal_2_or_5(n, 5) - cal_2_or_5(m, 5) - cal_2_or_5(n - m, 5);
    
    cout << min(num_2, num_5);

    return 0;
}

long long int cal_2_or_5(long long int num, int b)
{
    long long int counter = 0;
    
    for(long long int i=b; i<=num; i*=b)
    {
        counter += num / i;
    }
    
    return counter;
}
