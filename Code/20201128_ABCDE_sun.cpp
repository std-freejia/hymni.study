#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2000;
const int target = 5;
int N = 0;
int M = 0;
int visited[MAX] = {0};
vector<int> relation[MAX];

int DFS(int start, int counter);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a = 0;
    int b = 0;
    int i = 0;  // for loop
    
    cin>>N>>M;
    
    for(i=0; i<M; i++)
    {
        cin>>a>>b;
        
        relation[a].push_back(b);
        relation[b].push_back(a);
    }
    
    for(i=0; i<N; i++)
    {
        DFS(i, 1);
    }
    
    cout<<0;
    
    return 0;
}

int DFS(int start, int counter)
{
    visited[start] = 1;
    
    if(counter == target)
    {
        cout<<1;
        
        exit(0);
    }
    
    for(int i=0; i<relation[start].size(); i++)
    {
        if(!visited[relation[start][i]])
        {
            DFS(relation[start][i], counter + 1);
        }
    }
    
    visited[start] = 0;
    
    return 0;
}
