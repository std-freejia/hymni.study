#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop

    cin >> N;

    vector<int> A(N);
    vector<int> len(N, 1);

    for (i = 0; i < N; i++)
    {
        cin >> A[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (A[j] < A[i])
            {
                len[i] = max(len[i], len[j] + 1);
            }
        }
    }

    cout << *max_element(len.begin(), len.end());

    return 0;
}
