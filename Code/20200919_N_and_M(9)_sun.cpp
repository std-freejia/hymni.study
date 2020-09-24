#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 8;
int N = 0;
int M = 0;
int checked[MAX] = { 0 };
vector<int> arr;
vector<int> seq;
vector<vector<int>> all_seq;

int find_seq(int counter);

int main(int argc, char* argv[], char* envs[])
{
    int num = 0;
    int i = 0;  // for loop

    cin >> N >> M;

    for (i = 0; i < N; i++)
    {
        cin >> num;

        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    int counter = 0;
    find_seq(counter);

    sort(all_seq.begin(), all_seq.end());

    for (i = 0; i < all_seq.size(); i++)
    {
        if (i > 0 && all_seq[i] == all_seq[i - 1])
        {
            continue;
        }

        for (int j = 0; j < M; j++)
        {
            cout << all_seq[i][j] << ' ';
        }

        cout << "\n";
    }

    return 0;
}

int find_seq(int counter)
{
    if (counter == M)
    {
        all_seq.push_back(seq);

        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        if (checked[i] == 0)
        {
            checked[i] = 1;
            seq.push_back(arr[i]);

            find_seq(counter + 1);

            checked[i] = 0;
            seq.pop_back();
        }
    }

    return 0;
}
