#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char* argv[], char* envs[])
{
    int i = 0;
    int N = 0;
    int counter = 0;
    vector<char> op;
    stack<int> s;
    
    cin>>N;
    
    int seq[N] = {0};
    
    s.push(0);
    
    for(i=0; i<N ;i++)
    {
        cin>>seq[i];
    }
    
    for(i=0; i<N ;i++)
    {
        while(s.top()!= seq[i])
        {
            if(counter == N)
            {
                cout<<"NO\n";
                
                return 0;
            }
            
            counter++;
            
            s.push(counter);
            op.push_back('+');
        }
        
        s.pop();
        op.push_back('-');
    }
    
    for(i=0; i<op.size(); i++)
    {
        cout<<op[i]<<"\n";
    }
    
    return 0;
}
