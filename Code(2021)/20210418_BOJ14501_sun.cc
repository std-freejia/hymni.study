#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 15;
int N = 0;
int ans = 0;
int T[MAX] = {};
int P[MAX] = {};

int pick(int day, int income);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> T[i] >> P[i];
    }

    pick(0, 0);

    cout << ans;

    return 0;
}

int pick(int day, int income)
{
    if (day == N)
    {
        ans = max(ans, income);

        return 0;
    }

    if (day + T[day] <= N)
    {
        pick(day + T[day], income + P[day]);
    }

    pick(day + 1, income);

    return 0;
}
