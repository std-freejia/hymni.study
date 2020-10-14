#include <iostream>
#include <cstring>

using namespace std;

const int MAX_num = 10;
int N = 0;
int A[MAX_num] = { 0 };
string s = " ";

int find_seq(int counter);
int check(int counter);

int main(int argc, char* argv[], char* envs[])
{
    cin >> N;
    cin >> s;

    find_seq(0);

    return 0;
}

int find_seq(int counter)
{
    if (counter > 0 && !check(counter))
    {
        return 0;
    }

    if (counter == N)
    {
        for (int i = 0; i < N; i++)
        {
            cout << A[i] << " ";
        }

        exit(0);
    }

    for (int i = -10; i < 11; i++)
    {
        A[counter] = i;

        find_seq(counter + 1);
    }

    return 0;
}

int check(int counter)
{
    int sum = 0;
    int index = 0;

    for (int i = 0; i < counter; i++)
    {
        sum = A[i];

        for (int j = i; j < counter; j++)
        {
            sum += A[j];

            if (j == i + 1)
            {
                sum -= A[i];
            }

            index = N * i - i * (i - 1) / 2 + j - i;

            if (sum > 0 && s[index] != '+'
                || sum < 0 && s[index] != '-'
                || sum == 0 && s[index] != '0')
            {
                return 0;
            }
        }
    }

    return 1;
}
