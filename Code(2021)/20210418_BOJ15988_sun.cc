#include <iostream>

using namespace std;

const int MAX = 1000000;
const int divisor = 1000000009;
unsigned int ans[MAX + 1] = {};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;
    int n = 0;

    cin >> T;

    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;

    for (int i = 4; i <= MAX; i++)
    {
        ans[i] = (ans[i - 3] + ans[i - 2] + ans[i - 1]) % divisor;
    }

    while (T--)
    {
        cin >> n;

        cout << ans[n] << '\n';
    }
    
    return 0;
}
