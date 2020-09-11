#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 50;
int N = 0;
char board[MAX_SIZE][MAX_SIZE] = { 0 };
int max_counter = 0;

int swap_candy();
int find_same();

int main(int argc, char* argv[], char* envs[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    swap_candy();

    cout << max_counter << endl;

    return 0;
}

int swap_candy()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // right
            if ((j + 1 < N) && (board[i][j] != board[i][j + 1]))
            {
                swap(board[i][j], board[i][j + 1]);

                find_same();

                swap(board[i][j], board[i][j + 1]);
            }

            // below
            if ((i + 1 < N) && (board[i][j] != board[i + 1][j]))
            {
                swap(board[i][j], board[i + 1][j]);

                find_same();

                swap(board[i][j], board[i + 1][j]);
            }
        }
    }

    return 0;
}

int find_same()
{
    int row = 0;
    int col = 0;
    int temp = 0;
    int row_counter = 0;
    int col_counter = 0;

    // check row
    for (row = 0; row < N; row++)
    {
        temp = 1;

        for (col = 1; col < N; col++)
        {
            if (board[row][col] == board[row][col - 1])
            {
                temp++;
            }
            else
            {
                temp = 1;
            }

            max_counter = max(max_counter, temp);
        }
    }

    // check col
    for (col = 0; col < N; col++)
    {
        temp = 1;

        for (row = 1; row < N; row++)
        {
            if (board[row][col] == board[row - 1][col])
            {
                temp++;
            }
            else
            {
                temp = 1;
            }

            max_counter = max(max_counter, temp);
        }
    }

    return 0;
}
