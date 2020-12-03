#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 11;
int N = 0;
int max_result = -1000000000;
int min_result = 1000000000;
int A[MAX_N] = { 0 };
int op[4] = { 0 };

int calculation(int index, int result, int op[4]);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 0;  // for loop
    int j = 0;  // for loop
    int index = 0;

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < 4; i++)
    {
        cin >> op[i];
    }

    calculation(index, A[index], op);

    cout << max_result << "\n";
    cout << min_result << "\n";

    return 0;
}

int calculation(int index, int result, int op[4])
{
    if (index == N - 1)
    {
        max_result = max(max_result, result);
        min_result = min(min_result, result);

        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i])
        {
            op[i]--;

            switch (i)
            {
                case 0:
                {
                    calculation(index + 1, result + A[index + 1], op);
                    break;
                }

                case 1:
                {
                    calculation(index + 1, result - A[index + 1], op);
                    break;
                }

                case 2:
                {
                    calculation(index + 1, result * A[index + 1], op);
                    break;
                }

                case 3:
                {
                    calculation(index + 1, result / A[index + 1], op);
                }
            }

            op[i]++;
        }
    }

    return 0;
}
