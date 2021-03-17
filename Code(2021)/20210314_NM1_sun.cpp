#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 8;
bool used[MAX + 1] = { 0 };
int N = 0;
int M = 0;

int combination(string seq);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    combination("");
    
    return 0;
}

int combination(string seq)
{
    if (seq.size() == M)
    {
        for (int i = 0; i < seq.size(); i++)
        {
            cout << seq[i] << ' ';
        }
        cout << '\n';

        return 0;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            combination(seq + to_string(i));
            used[i] = 0;
        }
    }

    return 0;
}
