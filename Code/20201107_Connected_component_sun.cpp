/*
1. DFS
2. 
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000;
int N = 0;
int M = 0;
vector<int> graph[MAX_N + 1];  // 인접 노드
int visited[MAX_N + 1] = {0};  // 방문 체크

int DFS(int current);
int done(int current);  //끝점 판단

int main(int argc, char* argv[], char* envs[])
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int u = 0;
    int v = 0;
    int counter = 0;
    
    cin>>N>>M;
    
    // 그래프 만들기
    for(int i=0; i<M; i++)
    {
        cin>>u>>v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // DFS 한번 돌리고 나서 방문하지 못한 노드는 다른 연결 요소에 속함
    for(int i=1; i<=N; i++)
    {
        if(!visited[i])
        {    
            DFS(i);  // 아직 방문하지 않은 노드부터 DFS 돌리기
            
            counter++;  // 한개 연결 요소 찾았음
        }
    }
    
    cout<<counter;
    
    return 0;
}

int DFS(int current)
{
    visited[current] = 1;  // 방문 체크
    
    // 끝점인 경우 return
    if(done(current))
    {
        return 0;
    }
    
    // 미방문 인접 노드로 계속 DFS
    for(int i=0; i<graph[current].size(); i++)
    {
        if(!visited[graph[current][i]])
        {
            DFS(graph[current][i]);
        }
    }    
        
    return 0;
}

int done(int current)
{
    for(int i=0; i<graph[current].size(); i++)
    {
        // 미방문 인접 노드 존재하면 끝점 아니다
        if(!visited[graph[current][i]])
        {
            return 0;
        }
    }    
        
    return 1;
}
