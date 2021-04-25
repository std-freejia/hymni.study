#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;
int A[MAX] = {};
int len[MAX] = {};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int i = 0;
    int j = 0;

    cin >> N;
    
    for (i = 0; i < N; i++)
    {
        cin >> A[i];

        for (j = 0; j < i; j++)
        {
            if (A[j] > A[i])
            {
                len[i] = max(len[i], len[j] + 1);
            }
        }
    }

    cout << *max_element(len, len + N) + 1;

    return 0;
}
