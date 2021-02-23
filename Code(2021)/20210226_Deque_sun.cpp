#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int num = 0;
    string op = "";
    deque<int> dq;

    cin >> N;

    while (N--)
    {
        cin >> op;

        if (op == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if (op == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }
        else if (op == "pop_front")
        {
            if (!dq.empty())
            {
                cout << dq.front() <<'\n';
                dq.pop_front();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (op == "pop_back")
        {
            if (!dq.empty())
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (op == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (op == "empty")
        {
            cout << dq.empty() << '\n';
        }
        else if (op == "front")
        {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        }
        else if (op == "back")
        {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        }
    }
   
    return 0;
}
