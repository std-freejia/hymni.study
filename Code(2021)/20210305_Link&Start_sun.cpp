#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 20;
int S[MAX][MAX] = { 0 };
int N = 0;
int ans = 40000;
vector<int> start;
vector<int> link;

int divide_team(int id);
int calcu();

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 0;  // for loop
    int j = 0;  // for loop

    cin >> N;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> S[i][j];
        }
    }

    divide_team(0);

    cout << ans;

    return 0;
}

int divide_team(int id)
{
    if (id == N)
    {
        if (start.size() && link.size())
        {
            ans = min(ans, calcu());
        }

        return 0;
    }

    start.push_back(id);
    divide_team(id + 1);
    start.pop_back();

    link.push_back(id);
    divide_team(id + 1);
    link.pop_back();

    return 0;
}

int calcu()
{
    int s_sum = 0;
    int l_sum = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop

    for (i = 0; i < start.size(); i++)
    {
        for (j = i + 1; j < start.size(); j++)
        {
            s_sum += (S[start[i]][start[j]] + S[start[j]][start[i]]);
        }
    }

    for (i = 0; i < link.size(); i++)
    {
        for (j = i + 1; j < link.size(); j++)
        {
            l_sum += (S[link[i]][link[j]] + S[link[j]][link[i]]);
        }
    }

    return abs(s_sum - l_sum);
}
