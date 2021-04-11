#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    int k = 0;
    long long multi = 0;
    string s = "";

    while (cin >> n)
    {
        k = to_string(n).size();
        s.resize(k, '1');
        multi = stoi(s);
        
        while (1)
        {
            if (!(multi %= n))
            {
                break;
            }

            multi = multi * 10 + 1;
            k++;
        }

        cout << k << '\n';
    }

    return 0;
}
