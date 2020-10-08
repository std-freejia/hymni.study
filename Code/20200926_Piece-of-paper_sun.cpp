#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct cell
{
    int row;
    int col;
};

const int MAX = 4;
int N = 0;
int M = 0;
int paper[MAX][MAX] = { 0 };
int checked[MAX][MAX] = { 0 };
int sum_max = 0;

int find_max_sum(cell curr, int sum);
cell next_cell(cell curr);

int main(int argc, char* argv[], char* envs[])
{
    string str = " ";

    cin >> N >> M;

    for (int row = 0; row < N; row++)
    {
        cin >> str;

        for (int col = 0; col < M; col++)
        {
            paper[row][col] = str[col] - '0';
        }
    }

    int sum = 0;
    cell curr = { 0, 0 };

    find_max_sum(curr, sum);

    cout << sum_max;

    return 0;
}

int find_max_sum(cell curr, int sum)
{
    if (curr.row == N)
    {
        sum_max = max(sum_max, sum);

        return 0;
    }

    if (checked[curr.row][curr.col])
    {
        find_max_sum(next_cell(curr), sum);

        return 0;
    }

    int i = 0;
    int j = 0;
    int temp_sum = 0;

    // 가로
    for (int m = 1; m <= (M - curr.col); m++)
    {
        temp_sum = 0;

        for (i = 0; i < m; i++)
        {
            if (checked[curr.row][curr.col + i])
            {
                break;
            }

            checked[curr.row][curr.col + i] = 1;
            temp_sum = temp_sum * 10 + paper[curr.row][curr.col + i];
        }

        find_max_sum(next_cell(curr), sum + temp_sum);

        for (j = 0; j < i; j++)
        {
            checked[curr.row][curr.col + j] = 0;
        }

        if (i < m)
        {
            break;
        }
    }

    // 세로
    for (int n = 2; n <= (N - curr.row); n++)
    {
        temp_sum = 0;

        for (i = 0; i < n; i++)
        {
            if (checked[curr.row + i][curr.col])
            {
                break;
            }

            checked[curr.row + i][curr.col] = 1;
            temp_sum = temp_sum * 10 + paper[curr.row + i][curr.col];
        }

        find_max_sum(next_cell(curr), sum + temp_sum);

        for (j = 0; j < i; j++)
        {
            checked[curr.row + j][curr.col] = 0;
        }

        if (i < n)
        {
            break;
        }
    }


    return 0;
}

cell next_cell(cell curr)
{
    cell next = { 0, 0 };

    if (curr.col < M - 1)
    {
        next = { curr.row, curr.col + 1 };
    }
    else
    {
        next = { curr.row + 1, 0 };
    }

    return next;
}
