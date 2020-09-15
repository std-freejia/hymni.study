#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char* argv[], char* envs[])
{
    int M = 0;
    char command = ' ';
    char para = ' ';
    string text = " ";
    stack<char> s1, s2;

    cin >> text;
    cin >> M;

    for (int i = 0; i < text.size(); i++)
    {
        s1.push(text[i]);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> command;

        switch (command)
        {
            case 'L':
            {
                if (!s1.empty())
                {
                    s2.push(s1.top());

                    s1.pop();
                }

                break;
            }
            
            case 'D':
            {
                if (!s2.empty())
                {
                    s1.push(s2.top());
                    
                    s2.pop();
                }
                
                break;
            }
            
            case 'B':
            {
                if (!s1.empty())
                {
                    s1.pop();
                }
                
                break;
            }
            
            case 'P':
            {
                cin >> para;
                
                s1.push(para);
            }
        }
    }
    
    while(!s1.empty())
    {
        s2.push(s1.top());
        
        s1.pop();
    }
    
    while(!s2.empty())
    {
        cout<<s2.top();

        s2.pop();
    }
    
    return 0;
}
