#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
	int N = 0;
	int K = 0;
	int row = 0;
	int col = 0;
	int i = 0;  // for loop
	long long int Answer;
	string move = "";

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N >> K;
		cin >> move;

		Answer = 1;
		row = 0;
		col = 0;

		for (i = 0; i < K; i++)
		{
			switch (move[i])
			{
			case 'U':
			{
				row--;
				break;
			}
			case 'D':
			{
				row++;
				break;
			}
			case 'L':
			{
				col--;
				break;
			}
			case 'R':
			{
				col++;
				break;
			}
			}

			if (row + col < N)
			{
			    Answer += ((((long long)(row + col + 1)) * (row + col + 2) / 2) - (((row + col) & 1) ? col : row));
			}
			else
			{
				Answer += ((long long)N * N - (((long long)(2 * N - row - col - 2)) * (2 * N - row - col - 1) / 2) - N + 1 + (((row + col) & 1) ? row : col));
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
