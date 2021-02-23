#include <iostream>

using namespace std;

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    long long answer = 0;
    
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        answer += (long long)i * (N / i);
    }

    cout << answer << '\n';

    return 0;
}
