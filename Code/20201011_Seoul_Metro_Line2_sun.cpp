/*
1. DFS로 circle 찾기
2. circle 형성한 지를 판단하기 위해 시작 역의 번호를 저장 (start)\
3. 지선에 있는 역의 거리를 재귀하면서 계속 update
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_NUM = 3000;
int N = 0;
int start = 0;
int dis[MAX_NUM + 1] = {0};  // 각 역과 순환선 사이의 거리
int visited[MAX_NUM + 1] = {0};  // 중복 방문 방지
vector<int> edge[MAX_NUM + 1];  // 역과 역을 연결하는 정보

int DFS(int node, int counter);

int main(int argc, char* argv[], char* envs[])
{
    int a = 0;
    int b = 0;
    int i = 0;
    
    // 입력
    cin>>N;
    
    for(i=0; i<N; i++)
    {
        cin>>a>>b;
        
        // 연결된 역을 저장
        edge[a].push_back(b);
        edge[b].push_back(a);
        
        // 거리들을 최대값으로 초기화
        dis[i + 1] = MAX_NUM;
    }
    // 입력 끝
    
    // 모든 역을 시작 역으로 지정하고 거리 계산
    for(start=1; start<=N; start++)
    {
        DFS(start, 1);
    }
    
    // 출력
    for(i=1; i<=N; i++)
    {
        cout<<dis[i]<<" ";
    }
    // 출략 끝
    
    return 0;
}

int DFS(int node, int counter)
{
    // 2개 이상 역으로 구성하고 마지막 역은 start 역이랑 연결되어야 circle 형성할 수 있음
    if(counter > 2 &&
       find(edge[node].begin(), edge[node].end(), start) != edge[node].end())
    {
        // circle 구성하는 모든 역이 순환선에 있고 거리는 0
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
    
    // 지금 역이랑 연결된 역을 모두 확인
    for(int i=0; i<edge[node].size(); i++)
    {
        // 중복 방문 체크
        if(!visited[edge[node][i]])
        {
            // 거리 update (최솟값으로 배꿈)
            dis[edge[node][i]] = min(dis[edge[node][i]], dis[node] + 1);
            
            DFS(edge[node][i], counter + 1);
        }
    }
    
    visited[node] = 0;
    
    return 0;
}
