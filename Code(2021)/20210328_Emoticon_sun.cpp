#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;
int visited[MAX + 1][MAX + 1] = {};

int BFS(int S);
bool check_bound(pair<int, int> status);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S = 0;

    cin >> S;

    BFS(S);

    return 0;
}

int BFS(int S)
{
    pair<int, int> curr = {};
    pair<int, int> next = {};
    int i = 0;  // for loop
    queue<pair<int, int>> q;

    q.push({1, 0});
    visited[1][0] = 1;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        if (curr.first == S)
        {
            cout << visited[curr.first][curr.second] - 1;

            break;
        }

        // copy
        next.first = curr.first;
        next.second = curr.first;

        if (check_bound(next) && !visited[next.first][next.second])
        {
            q.push(next);
            visited[next.first][next.second] = visited[curr.first][curr.second] + 1;
        }

        // paste
        next.first = curr.first + curr.second;
        next.second = curr.second;

        if (check_bound(next) && !visited[next.first][next.second])
        {
            q.push(next);
            visited[next.first][next.second] = visited[curr.first][curr.second] + 1;
        }

        // delete
        next.first = curr.first - 1;
        next.second = curr.second;

        if (check_bound(next) && !visited[next.first][next.second])
        {
            q.push(next);
            visited[next.first][next.second] = visited[curr.first][curr.second] + 1;
        }
    }

    return 0;
}

bool check_bound(pair<int, int> status)
{
    if (0 <= status.first && status.first <= MAX && 0 <= status.second && status.second <= MAX)
        return 1;
    return 0;
}
