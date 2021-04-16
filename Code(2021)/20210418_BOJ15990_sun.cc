#include <iostream>

using namespace std;

const int MAX = 100000;
const int divisor = 1000000009;
unsigned int ans[MAX + 1][3] = {};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;
    int n = 0;

    cin >> T;

    ans[1][0] = 1;

    ans[2][1] = 1;
    
    ans[3][0] = 1;
    ans[3][1] = 1;
    ans[3][2] = 1;

    for (int i = 4; i <= MAX; i++)
    {
        ans[i][0] = (ans[i - 1][1] + ans[i - 1][2]) % divisor;
        ans[i][1] = (ans[i - 2][0] + ans[i - 2][2]) % divisor;
        ans[i][2] = (ans[i - 3][0] + ans[i - 3][1]) % divisor;
    }

    while (T--)
    {
        cin >> n;

        cout << (ans[n][0] + ans[n][1] + ans[n][2]) % divisor << '\n';
    }
    
    return 0;
}
