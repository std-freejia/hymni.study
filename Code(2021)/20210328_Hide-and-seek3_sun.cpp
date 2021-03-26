#include <iostream>
#include <deque>

using namespace std;

const int MAX = 100000;
int visited[MAX + 1] = {};

int BFS(int N, int K);

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

int BFS(int N, int K)
{
    int curr = 0;
    int next = 0;
    deque<int> q;

    q.push_back(N);
    visited[N] = 1;

    while (!empty(q))
    {
        curr = q.front();
        q.pop_front();

        if (curr == K)
        {
            cout << visited[K] - 1;

            break;
        }

        // 2*X
        next = curr * 2;

        if (next <= MAX && !visited[next])
        {
            q.push_front(next);
            visited[next] = visited[curr];
        }

        // X-1
        next = curr - 1;

        if (next >= 0 && !visited[next])
        {
            q.push_back(next);
            visited[next] = visited[curr] + 1;
        }

        // X+1
        next = curr + 1;

        if (next <= MAX && !visited[next])
        {
            q.push_back(next);
            visited[next] = visited[curr] + 1;
        }
    }

    return 0;
}
