#include <iostream>

using namespace std;

const int MAX = 7;
int seq[MAX] = { 0 };
int N = 0;
int M = 0;

int combination(int count);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    combination(0);
    
    return 0;
}

int combination(int count)
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

    for (int i = 1; i <= N; i++)
    {
        seq[count] = i;
        combination(count + 1);
    }

    return 0;
}
