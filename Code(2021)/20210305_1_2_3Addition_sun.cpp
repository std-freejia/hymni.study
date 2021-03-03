#include <iostream>

using namespace std;

const int MAX = 11;
int ans[MAX + 1] = { 0 };

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;
    int n = 0;

    cin >> T;

    ans[0] = 1;
    
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if (i - j >= 0)
            {
                ans[i] += ans[i - j];
            }
        }
    }

    while(T--)
    {
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}
