#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int ans[MAX + 1] = {};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int temp = 0;
    int j = 0;  // for loop
    
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        temp = (int)sqrt(i);
        
        ans[i] = MAX;

        for (j = 1; j <= temp; j++)
        {
            ans[i] = min(ans[i], ans[i - j * j] + 1);
        }
    }

    cout << ans[N] << '\n';
    
    return 0;
}
