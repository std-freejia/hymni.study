#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;
int price[MAX][3] = { 0 };

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop

    cin >> N;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> price[i][j];
        }
    }

    for (i = 1; i < N; i++)
    {
        price[i][0] += min(price[i - 1][1], price[i - 1][2]);
        price[i][1] += min(price[i - 1][0], price[i - 1][2]);
        price[i][2] += min(price[i - 1][0], price[i - 1][1]);
    }

    cout << *min_element(price[N - 1], price[N - 1] + 3);

    return 0;
}
