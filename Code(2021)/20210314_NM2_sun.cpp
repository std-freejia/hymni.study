#include <iostream>

using namespace std;

const int MAX = 8;
int seq[MAX] = { 0 };
int N = 0;
int M = 0;

int combination(int idx, int count);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    combination(1, 0);
    
    return 0;
}

int combination(int idx, int count)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << seq[i] << ' ';
        }
        cout << '\n';

        return 0;
    }

    for (int i = idx; i <= N; i++)
    {
        seq[count] = i;
        combination(i + 1, count + 1);
    }

    return 0;
}
