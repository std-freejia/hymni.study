#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;
int nums[MAX] = { 0 };
int seq[MAX] = { 0 };
bool used[MAX] = { 0 };
int N = 0;
int M = 0;

int combination(int count);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + N);

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

    for (int i = 0; i < N; i++)
    {
        if (!used[i])
        {
            seq[count] = nums[i];
            used[i] = 1;
            combination(count + 1);
            used[i] = 0;
        }
    }

    return 0;
}
