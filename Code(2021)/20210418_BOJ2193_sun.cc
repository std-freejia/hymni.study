#include <iostream>

using namespace std;

const int MAX = 90;
unsigned long ans[MAX + 1][2] = {};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;

    cin >> N;

    ans[1][0] = 0;
    ans[1][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        ans[i][0] = ans[i - 1][0] + ans[i - 1][1];
        ans[i][1] = ans[i - 1][0];
    }
    
    cout << ans[N][0] + ans[N][1];

    return 0;
}
