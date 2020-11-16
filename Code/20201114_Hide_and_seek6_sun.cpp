/*
1. 최대공약수 계산
2. 수빈이와 동생들의 거리의 최대공약수
*/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 100000;
int A[MAX_N] = {0};  // 수빈이와 동생의 거리 

int GCD(int A, int B);

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    int S = 0;
    int gcd = 0;
    int i = 0;  // for loop
    
    cin>>N>>S;
    
    // 동생 위치를 입력 받으면서 거리를 계산
    for(i=0; i<N; i++)
    {
        cin>>A[i];
        
        A[i] = abs(S - A[i]);
    }
    
    // 동생이 한명인 경우 최대공약수가 거리와 같다
    if(N == 1)
    {
        gcd = A[0];
    }
    else
    {
        // 먼저 0번, 1번 동생 거리의 최대공약수 계산
        gcd = GCD(A[0], A[1]);
    }
    
    // 2번, 3번... 동생 거리의 최대공약수 계산
    for(i=2; i<N; i++)
    {
        gcd = GCD(gcd, A[i]);
    }
    
    cout<<gcd;
    
    return 0;
}

int GCD(int A, int B)
{
    if(A % B == 0)
    {
        return B;
    }
    else
    {
        return GCD(B, A % B);
    }
}
