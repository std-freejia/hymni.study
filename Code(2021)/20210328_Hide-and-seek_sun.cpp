#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;
int visited[MAX + 1] = {};

int BFS(int s, int e);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int K = 0;

    cin >> N >> K;

    BFS(N, K);

    return 0;
}

int BFS(int s, int e)
{
    queue<int> q;
    int curr = 0;
    int next = 0;
    int i = 0;  // for loop

    q.push(s);
    visited[s] = 1;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        if (curr == e)
        {
            cout << visited[e] - 1;

            break;
        }

        for (i = 0; i < 3; i++)
        {
            if(i == 0)
            {
                next = curr - 1;
            }
            else if (i == 1)
            {
                next = curr + 1;
            }
            else
            {
                next = curr * 2;
            }

            if (0 <= next && next <= MAX && !visited[next])
            {
                q.push(next);
                visited[next] = visited[curr] + 1;
            }
        }
    }

    return 0;
}
