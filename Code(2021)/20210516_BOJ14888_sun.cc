#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 11;
int N = 0;
int A[MAX] = {};
int ops[4] = {};
int max_ans = -1000000000;
int min_ans = 1000000000;

int calcu(int index, int plus, int min, int mul, int div, int answer);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 0;  // for loop

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < 4; i++)
    {
        cin >> ops[i];
    }

    calcu(1, ops[0], ops[1], ops[2], ops[3], A[0]);

    cout << max_ans << '\n';
    cout << min_ans << '\n';

    return 0;
}

int calcu(int index, int plus, int minu, int mul, int div, int answer)
{
    if (index >= N)
    {
        max_ans = max(max_ans, answer);
        min_ans = min(min_ans, answer);

        return 0;
    }

    if (plus)
    {
        calcu(index + 1, plus - 1, minu, mul, div, answer + A[index]);
    }

    if (minu)
    {
        calcu(index + 1, plus, minu - 1, mul, div, answer - A[index]);
    }

    if (mul)
    {
        calcu(index + 1, plus, minu, mul - 1, div, answer * A[index]);
    }

    if (div)
    {
        calcu(index + 1, plus, minu, mul, div - 1, answer / A[index]);
    }

    return 0;
}
