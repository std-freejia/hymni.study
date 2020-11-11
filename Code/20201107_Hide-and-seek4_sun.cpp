/*
1. 가중치 같아서 일반 BFS 사용
2. 경로를 찾기 위해 각 노드의 parent 저장
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000;
int visited[MAX + 1] = {0};  // 방문 체크
int parent[MAX + 1] = {0};  // 노드의 parent
queue<int> bfs_q;
vector<int> path;  // 최단 경로

int BFS(int start, int target);

int main(int argc, char* argv, char* envs[])
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N = 0;
    int K = 0;

    cin>>N>>K;
    
    BFS(N, K);
    
    return 0;
}

int BFS(int start, int target)
{
    int curr = 0;
    
    bfs_q.push(start);
    visited[start] = 1;
    parent[start] = start;  // 시작 노드의 parent가 자신
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        // 동생 위치 도착
        if(curr == target)
        {
            cout<<visited[curr] - 1<<"\n";  // 경로 길이 출력
            
            int point = curr;
            
            // 순환으로 dst->src 노드 번호 찾기
            while(1)
            {
                // path에 저장
                path.push_back(point);
                
                // src 노드까지 찾았다
                if(parent[point] == point)
                {
                    break;
                }
                
                point = parent[point];
            }
            
            // dst->src 역순으로 최단 경로 출력
            for(int i=path.size() - 1; i>=0; i--)
            {
                cout<<path[i]<<" ";
            }
            
            return 0;
        }
        
        // X+1 위치
        if(curr + 1 <= 100000 && !visited[curr + 1])
        {
            bfs_q.push(curr + 1);
            visited[curr + 1] = visited[curr] + 1;
            parent[curr + 1] = curr;
        }
        
        // X-1 위치
        if(0 <= curr - 1 && !visited[curr - 1])
        {
            bfs_q.push(curr - 1);
            visited[curr - 1] = visited[curr] + 1;
            parent[curr - 1] = curr;
        }
        
        // 2*X 위치
        if((0 <= 2 * curr) && (2 * curr <= 100000) && !visited[2 * curr])
        {
            bfs_q.push(2 * curr);
            visited[2 * curr] = visited[curr] + 1;
            parent[2 * curr] = curr;
        }
    }
    
    return 0;
}
