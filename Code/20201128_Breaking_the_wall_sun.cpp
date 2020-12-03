#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int row;
    int col;
    int can_smash;
};

const int MAX = 1000;
int N = 0;
int M = 0;
int diff_dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int visited[MAX][MAX][2] = { 0 };
vector<string> map;
queue<pos> bfs_q;

int BFS();

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = " ";
    
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> s;

        map.push_back(s);
    }

    BFS();

    return 0;
}

int BFS()
{
    int i = 0;  // for loop
    pos curr = { 0, 0, 0 };
    pos next = { 0, 0, 0 };

    bfs_q.push({ 0, 0, 1 });
    visited[0][0][1] = 1;

    while (!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();

        if (curr.row == N - 1 && curr.col == M - 1)
        {
            cout<<visited[curr.row][curr.col][curr.can_smash];

            return 0;
        }

        for (i = 0; i < 4; i++)
        {
            next.row = curr.row + diff_dir[i][0];
            next.col = curr.col + diff_dir[i][1];
            next.can_smash = curr.can_smash;
            
            if (0 <= next.row && next.row < N &&
                0 <= next.col && next.col < M)
            {
                if (map[next.row][next.col] == '0' &&
                   !visited[next.row][next.col][next.can_smash])
                {
                    bfs_q.push(next);
                    visited[next.row][next.col][next.can_smash] = visited[curr.row][curr.col][curr.can_smash] + 1;
                }

                if (map[next.row][next.col] == '1' && next.can_smash)
                {
                    next.can_smash = 0;
                    bfs_q.push(next);
                    visited[next.row][next.col][next.can_smash] = visited[curr.row][curr.col][curr.can_smash] + 1;
                }
            }
        }
    }

    cout << -1;

    return 0;
}
