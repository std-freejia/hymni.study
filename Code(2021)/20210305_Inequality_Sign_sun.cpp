#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 10;
int visited[MAX] = { 0 };
char op[MAX] = { 0 };
int k = 0;
long long max_ans = 0;
long long min_ans = 9876543210;

int fill(int id, long long num);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string temp = "";

    cin >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> op[i];
    }

    fill(0, 0);

    temp = to_string(max_ans);
    cout << (temp.size() == k ? "0" : "") + temp << '\n';
    
    temp = to_string(min_ans);
    cout << (temp.size() == k ? "0" : "") + temp << '\n';

    return 0;
}

int fill(int id, long long num)
{
    if (id > k)
    {
        max_ans = max(max_ans, num);
        min_ans = min(min_ans, num);

        return 0;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (!visited[i])
        {
            if (op[id] == '<' && i < (num % 10)
                || op[id] == '>' && i > (num % 10))
            {
                continue;
            }

            visited[i] = 1;
            fill(id + 1, num * 10 + i);
            visited[i] = 0;
        }
    }

    return 0;
}
