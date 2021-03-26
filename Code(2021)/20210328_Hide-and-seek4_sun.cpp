#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100000;
int parent[MAX + 1] = {};

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
    int curr = 0;
    int next = 0;
    int i = 0;  // for loop
    queue<int> q;
    vector<int> path;

    q.push(s);
    parent[s] = s + 1;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        if (curr == e)
        {
            while (1)
            {
                path.push_back(curr);

                if (parent[curr] == curr + 1)
                {
                    break;
                }

                curr = parent[curr] - 1;
            }

            cout << path.size() - 1 << '\n';

            for (i = path.size() - 1; i >= 0; i--)
            {
                cout << path[i] << ' ';
            }

            break;
        }

        for (i = 0; i < 3; i++)
        {
            if (i == 0)
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

            if (0 <= next && next <= MAX && !parent[next])
            {
                q.push(next);
                parent[next] = curr + 1;
            }
        }
    }

    return 0;
}
