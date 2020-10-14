#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_NUM = 3000;
int N = 0;
int start = 0;
int dis[MAX_NUM + 1] = {0};
int visited[MAX_NUM + 1] = {0};
vector<int> edge[MAX_NUM + 1];

int DFS(int node, int counter);

int main(int argc, char* argv[], char* envs[])
{
    int a = 0;
    int b = 0;
    int i = 0;
    
    cin>>N;
    
    for(i=0; i<N; i++)
    {
        cin>>a>>b;
        
        edge[a].push_back(b);
        edge[b].push_back(a);
        
        dis[i + 1] = MAX_NUM;
    }
    
    for(start=1; start<=N; start++)
    {
        DFS(start, 1);
    }
    
    for(i=1; i<=N; i++)
    {
        cout<<dis[i]<<" ";
    }
    
    return 0;
}

int DFS(int node, int counter)
{
    if(counter > 2 &&
       find(edge[node].begin(), edge[node].end(), start) != edge[node].end())
    {
        for(int i=1; i<=N; i++)
        {
            if(visited[i] == 1)
            {
                dis[i] = 0;
            }
        }
        
        return 0;
    }
    
    visited[node] = 1;
    
    for(int i=0; i<edge[node].size(); i++)
    {
        if(!visited[edge[node][i]])
        {
            dis[edge[node][i]] = min(dis[edge[node][i]], dis[node] + 1);
            
            DFS(edge[node][i], counter + 1);
        }
    }
    
    visited[node] = 0;
    
    return 0;
}
