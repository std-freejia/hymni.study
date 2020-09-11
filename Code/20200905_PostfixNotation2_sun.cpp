#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

int N = 0;
string postfix;
vector<int> value;

int cal_postfix();

int main(int argc, char* argv[], char* envs[])
{
    int val = 0;

    cin >> N;
    cin >> postfix;

    for (int i = 0; i < N; i++)
    {
        cin >> val;

        value.push_back(val);
    }

    cal_postfix();

    return 0;
}

int cal_postfix()
{
    stack<double> s;
    double op1 = 0;
    double op2 = 0;

    for (int i = 0; i < postfix.size(); i++)
    {
        if ('A' <= postfix[i] && postfix[i] <= 'Z')
        {
            s.push(value[postfix[i] - 'A']);
        }
        else
        {
            op2 = s.top();
            s.pop();

            op1 = s.top();
            s.pop();

            switch (postfix[i])
            {
                case '+':
                {
                    s.push(op1 + op2);
                    break;
                }
                case '-':
                {
                    s.push(op1 - op2);
                    break;
                }
                case '*':
                {
                    s.push(op1 * op2);
                    break;
                }
                case '/':
                {
                    s.push(op1 / op2);
                }
            }
        }
    }

    cout << fixed << setprecision(2) << s.top() << endl;
    
    return 0;
}
