#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
int P[MAX_N + 1] = {0};
int pay[MAX_N + 1] = {0};
int N = 0;

int main(int argc, char* argv[], char* envs[])
{
    cin>>N;
    
    for(int i=1; i<=N; i++)
    {
        cin>>P[i];
        
        for(int j=1; j<=i; j++)
        {
            pay[i] = max(pay[i], pay[i - j] + P[j]);
        }
    }
    
    cout<<pay[N];
    
    return 0;
}
