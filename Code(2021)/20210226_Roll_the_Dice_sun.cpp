#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 20;
int map[MAX][MAX] = { 0 };
int cmds[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int dice[7] = { 0 };
int dir[3] = { 1, 2, 3 };
int N = 0;
int M = 0;
int x = 0;
int y = 0;

int roll(int cmd);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K = 0;
    int cmd = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop

    cin >> N >> M >> x >> y >> K;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    while (K--)
    {
        cin >> cmd;

        roll(cmd);
    }

    return 0;
}

int roll(int cmd)
{
    cmd--;

    int next_x = x + cmds[cmd][0];
    int next_y = y + cmds[cmd][1];

    if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
    {
        return 0;
    }

    switch (cmd)
    {
        case 0:
        {
            swap(dir[0], dir[2]);
            dir[0] = 7 - dir[0];
            break;
        }
        case 1:
        {
            swap(dir[0], dir[2]);
            dir[2] = 7 - dir[2];
            break;
        }
        case 2:
        {
            swap(dir[0], dir[1]);
            dir[0] = 7 - dir[0];
            break;
        }
        case 3:
        {
            swap(dir[0], dir[1]);
            dir[1] = 7 - dir[1];
        }
    }

    map[next_x][next_y] ? dice[7 - dir[0]] = map[next_x][next_y], map[next_x][next_y] = 0 : map[next_x][next_y] = dice[7 - dir[0]];

    cout << dice[dir[0]] << '\n';

    x = next_x;
    y = next_y;

    return 0;
}
