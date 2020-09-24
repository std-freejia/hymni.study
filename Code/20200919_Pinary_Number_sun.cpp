#include <iostream>

using namespace std;

const int MAX_N = 90;

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    long long int last_bit[MAX_N + 1][2] = { 0 };

    cin >> N;

    last_bit[1][0] = 0;
    last_bit[1][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        last_bit[i][0] = last_bit[i - 1][0] + last_bit[i - 1][1];
        last_bit[i][1] = last_bit[i - 1][0];
    }

    cout << last_bit[N][0] + last_bit[N][1];

    return 0;
}
