#include <iostream>

using namespace std;

int LCM(int M, int N);
int GCD(int M, int N);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;
    int M = 0;
    int N = 0;
    int x = 0;
    int y = 0;
    int total = 0;
    int year = 0;
    int a = 0;

    cin >> T;

    while (T--)
    {
        cin >> M >> N >> x >> y;

        a = 0;
        year = x;
        total = LCM(M, N);
        
        while (year <= total)
        {
            if ((year - y) % N == 0)
            {
                break;
            }

            a++;
            year = a * M + x;
        }

        cout << (year > total ? -1 : year) << '\n';
    }

    return 0;
}

int LCM(int M, int N)
{
    return M * N / GCD(M, N);
}

int GCD(int M, int N)
{
    if (M % N == 0)
        return N;
    return GCD(N, M % N);
}
