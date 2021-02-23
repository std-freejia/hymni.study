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
    int M = 0;
    int R = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop
    int op = 0;

    cin >> N >> M >> R;

    vector<vector<int>> A(N, vector<int>(M));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    while (cin >> op)
    {
        N = A.size();
        M = A[0].size();

        switch(op)
        {
            case 1:
            {
                reverse(A.begin(), A.end());
                break;
            }
            case 2:
            {
                for (i = 0; i < A.size(); i++)
                {
                    reverse(A[i].begin(), A[i].end());
                }
                break;
            }
            case 3:
            {
                vector<vector<int>> B(M, vector<int>(N));

                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < M; j++)
                    {
                        B[j][N - 1 - i] = A[i][j];
                    }
                }

                A.clear();
                A = B;

                break;
            }
            case 4:
            {
                vector<vector<int>> B(M, vector<int>(N));

                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < M; j++)
                    {
                        B[M - 1 - j][i] = A[i][j];
                    }
                }

                A.clear();
                A = B;

                break;
            }
            case 5:
            {
                vector<vector<int>> B(N, vector<int>(M));

                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < M; j++)
                    {
                        if (i < N / 2)
                        {
                            B[i][j] = (j < M / 2 ? A[i + N / 2][j] : A[i][j - M / 2]);
                        }
                        else
                        {
                            B[i][j] = (j < M / 2 ? A[i][j + M / 2] : A[i - N / 2][j]);
                        }
                        
                    }
                }

                A = B;

                break;
            }
            case 6:
            {
                vector<vector<int>> B(N, vector<int>(M));

                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < M; j++)
                    {
                        if (i < N / 2)
                        {
                            B[i][j] = (j < M / 2 ? A[i][j + M / 2] : A[i + N / 2][j]);
                        }
                        else
                        {
                            B[i][j] = (j < M / 2 ? A[i - N / 2][j] : A[i][j - M / 2]);
                        }

                    }
                }

                A = B;
            }
        }
    }

    for (i = 0; i < A.size(); i++)
    {
        for (j = 0; j < A[0].size(); j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
