#include <iostream>
#include <string>
#include <deque>

using namespace std;

struct cell
{
    int row;
    int col;
};

const int MAX = 100;
int maze[MAX + 1][MAX + 1] = { 0 };
int visited[MAX + 1][MAX + 1] = { 0 };
int diff[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N = 0;
int M = 0;
deque<cell> path;

int BFS(cell start);

int main(int argc, char* argv[], char* envs[])
{
    string s = " ";
    cell start = { 1, 1 };

    cin >> M >> N;

    for (int row = 1; row <= N; row++)
    {
        cin >> s;

        for (int col = 1; col <= M; col++)
        {
            maze[row][col] = s[col - 1] - '0';
        }
    }

    BFS(start);

    cout << visited[N][M] - 1;

    return 0;
}

int BFS(cell start)
{
    cell curr = { 0, 0 };
    cell adj = { 0, 0 };

    path.push_back(start);
    visited[start.row][start.col] = 1;

    while (!path.empty())
    {
        curr = path.front();

        path.pop_front();

        if (curr.row == N && curr.col == M)
        {
            break;
        }

        if (maze[curr.row][curr.col] == 1)
        {
            visited[curr.row][curr.col]++;
        }

        for (int i = 0; i < 4; i++)
        {
            adj.row = curr.row + diff[i][0];
            adj.col = curr.col + diff[i][1];

            if (0 < adj.row && adj.row <= N && 0 < adj.col && adj.col <= M && !visited[adj.row][adj.col])
            {
                if (maze[adj.row][adj.col] == 0)
                {
                    path.push_front(adj);
                }
                else
                {
                    path.push_back(adj);
                }

                visited[adj.row][adj.col] = visited[curr.row][curr.col];
            }
        }
    }

    return 0;
}
