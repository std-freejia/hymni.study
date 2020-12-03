#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1000;
int N = 0;
int M = 0;
int V = 0;
int visited[MAX_N + 1] = {0};
//int graph[MAX_N + 1][MAX_N + 1] = {0};
vector<int> graph[MAX_N + 1];
queue<int> bfs_q;

int DFS(int curr);
int BFS();

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int adj_1 = 0;
    int adj_2 = 0;
    
    cin>>N>>M>>V;
    
    for(int i=0; i<M; i++)
    {
        cin>>adj_1>>adj_2;
        
        graph[adj_1].push_back(adj_2);
        graph[adj_2].push_back(adj_1);
        //graph[adj_1][adj_2] = 1;
        //graph[adj_2][adj_1] = 1;
    }
    
    for(int i=1; i<=N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    
    DFS(V);
    cout<<"\n";
    BFS();
    
    return 0;
}

int DFS(int curr)
{
    visited[curr] = 1;
    cout<<curr<<" ";
    
    //for(int i=1; i<=N; i++)
    for(int i=0; i<graph[curr].size(); i++)
    {
        //if(graph[curr][i] && !visited[i])
        if(!visited[graph[curr][i]])
        {
            //DFS(i);
            DFS(graph[curr][i]);
        }
    }
    
    return 0;
}

int BFS()
{
    int i = 0;  // for loop
    int curr = 0;
    
    memset(visited, 0, sizeof(visited));
    
    bfs_q.push(V);
    visited[V] = 1;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        cout<<curr<<" ";
        
        //for(i=1; i<=N; i++)
        for(i=0; i<graph[curr].size(); i++)
        {
            //if(graph[curr][i] && !visited[i])
            if(!visited[graph[curr][i]])
            {
                //bfs_q.push(i);
                //visited[i] = 1;
                
                bfs_q.push(graph[curr][i]);
                visited[graph[curr][i]] = 1;
            }
        }
    }
    
    return 0;
}
