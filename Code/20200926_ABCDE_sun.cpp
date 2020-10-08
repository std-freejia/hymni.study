#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2000;
const int MAX_LEN = 5;  // A-B B-C C-D D-E
int N = 0;
int M = 0;
vector<int> peer[MAX];
int visited[MAX] = {0};

int dfs(int start, int counter);

int main(int argc, char* argv[], char* envs[])
{
    int a = 0;
    int b = 0;
    int i = 0;
    
    cin>>N>>M;
    
    for(i=0; i<M; i++)
    {
        cin>>a>>b;
        
        peer[a].push_back(b);
        peer[b].push_back(a);
    }
    
    for(i=0; i<N; i++)
    {
        dfs(i, 1);
    }
    
    cout<<0;
    
    return 0;
}

int dfs(int start, int counter)
{
    visited[start] = 1;
    
    if(counter == MAX_LEN)
    {
        cout<<1;
        
        exit(0);
    }
    
    for(int i=0; i<peer[start].size(); i++)
    {
        if(!visited[peer[start][i]])
        {
            dfs(peer[start][i], counter + 1);
        }
    }
    
    visited[start] = 0;
    
    return 0;
}
