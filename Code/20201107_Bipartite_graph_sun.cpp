/*
1. BFS
2. 모든 노드가 속하는 집합을 1,2로 표시
3. 부모 노드가 1이면 자식 노드를 2로 표시;
   부모 노드가 2면 자식 노드를 1로 표시;
4. 인접 노드의 집합 번호가 같으면 이분 그래프 아니다
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V = 20000;
int part[MAX_V + 1] = {0};  // 노드의 집합 번호
vector<int> graph[MAX_V + 1];  // 인접 노드
queue<int> bfs_q;

int is_Bipartite_Graph(int V);
int BFS(int start);

int main(int argc, char* argv[], char* envs[])
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int K = 0;
    int V = 0;
    int E = 0;
    int node_1 = 0;
    int node_2 = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    cin>>K;
    
    for(i=0; i<K; i++)
    {
        cin>>V>>E;
        
        // graph 초기화
        for(j=1; j<=V; j++)
        {
            graph[j].clear();
        }
        
        for(j=0; j<E; j++)
        {
            cin>>node_1>>node_2;
            
            graph[node_1].push_back(node_2);
            graph[node_2].push_back(node_1);
        }
        
        is_Bipartite_Graph(V);
    }
    
    return 0;
}

int is_Bipartite_Graph(int V)
{
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    memset(part, 0, sizeof(part));  // part 배열 초기화
    bfs_q = queue<int>();  // 큐를 초기화
    
    // 여러개 연결 요소 있을 수 있다
    for(i=1; i<=V; i++)
    {
        if(!part[i])
        {
            BFS(i);
        }
    }
    
    // 이분 그래프인지 판단
    for(i=1; i<=V; i++)
    {
        for(j=0; j<graph[i].size(); j++)
        {
            // 인접 노드의 집합 번호가 같으면 이분 그래프 아니다
            if(part[i] == part[graph[i][j]])
            {
                cout<<"NO\n";
                
                return 0;
            }
        }
    }
    
    cout<<"YES\n";
    
    return 0;
}

int BFS(int start)
{
    int curr = 0;
    
    bfs_q.push(start);
    part[start] = 1;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        for(int i=0; i<graph[curr].size(); i++)
        {
            if(!part[graph[curr][i]])
            {
                bfs_q.push(graph[curr][i]);
                
                // 부모 노드가 1이면 자식 노드를 2로 표시;
                // 부모 노드가 2면 자식 노드를 1로 표시;
                if(part[curr] == 1)
                {
                    part[graph[curr][i]] = 2;
                }
                else
                {
                    part[graph[curr][i]] = 1;
                }
            }
        }
    }
    
    return 0;
}
