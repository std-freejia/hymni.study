#include <iostream>
#include <string>
#include <deque>

using namespace std;

const int MAX = 100;
const int dir_diff[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int visited[MAX][MAX] = {};
int maze[MAX][MAX] = {};

int BFS(int N, int M);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int M = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop
    string s = "";

    cin >> N >> M;

    for (i = 0; i < M; i++)
    {
        cin >> s;

        for (j = 0; j < N; j++)
        {
            maze[i][j] = s[j];
        }
    }

    BFS(N, M);

    return 0;
}

int BFS(int N, int M)
{
    int i = 0;  // for loop
    pair<int, int> curr = {};
    pair<int, int> next = {};
    deque<pair<int, int>> q;

    q.push_back({0, 0});
    visited[0][0] = 1;

    while (!empty(q))
    {
        curr = q.front();
        q.pop_front();
        
        if (curr.first == M - 1 && curr.second == N - 1)
        {
            cout << visited[M - 1][N - 1] - 1;

            break;
        }

        for (i = 0; i < 4; i++)
        {
            next.first = curr.first + dir_diff[i][0];
            next.second = curr.second + dir_diff[i][1];

            if (0 <= next.first && next.first < M && 0 <= next.second && next.second < N)
            {
                if (!visited[next.first][next.second])
                {
                    if (maze[next.first][next.second] == '1')
                    {
                        visited[next.first][next.second] = visited[curr.first][curr.second] + 1;
                        q.push_back(next);
                    }
                    else
                    {
                        visited[next.first][next.second] = visited[curr.first][curr.second];
                        q.push_front(next);
                    }
                }
            }
        }
    }

    return 0;
}
