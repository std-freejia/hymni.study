#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10;
int board[MAX * MAX] = { 0 };
int visited[MAX * MAX] = { 0 };
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N = 0;
int M = 0;
int K = 0;
int ans = -1000000;

int choose(int id, int counter, int sum);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 0;  // for loop
    int j = 0;  // for loop

    cin >> N >> M >> K;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> board[i * M + j];
        }
    }

    choose(0, 0, 0);

    cout << ans;

    return 0;
}

int choose(int id, int counter, int sum)
{
    int curr_x = 0;
    int curr_y = 0;
    int next_x = 0;
    int next_y = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop

    if (counter == K)
    {
        ans = max(ans, sum);
        
        return 0;
    }

    for (i = id; i < N * M; i++)
    {
        if (!visited[i])
        {
            curr_x = i / M;
            curr_y = i % M;

            visited[i]++;

            for (j = 0; j < 4; j++)
            {
                next_x = curr_x + dir[j][0];
                next_y = curr_y + dir[j][1];

                if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M)
                {
                    visited[next_x * M + next_y]++;
                }
            }

            choose(i + 1, counter + 1, sum + board[i]);

            visited[i]--;

            for (j = 0; j < 4; j++)
            {
                next_x = curr_x + dir[j][0];
                next_y = curr_y + dir[j][1];

                if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M)
                {
                    visited[next_x * M + next_y]--;
                }
            }
        }
    }

    return 0;
}
