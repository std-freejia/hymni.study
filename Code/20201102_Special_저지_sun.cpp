/*
1. 시작 노드는 항상 1 !!!
2. 노드 i의 미방문 인접 노드 개수가 n이면 i를 부모 노드로 볼때
   입력하는 n개의 노드가 반드시 i의 미방문 인접 노드여야 올바른
   순서다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 100000;
int N = 0;
vector<int> graph[MAX_N + 1];  // 인접 노드
int visited[MAX_N + 1] = {0};  // 방문 여부 체크
int seq[MAX_N] = {0};  // 입력한 노드 방문 순서

int main(int argc, char* argv[], char* envs[])
{
    // 시간 초과 방지
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int src = 0;
    int dst = 0;
    int id = 0;  // 부모 노드 index, 0으로 초기화
    int n = 1;
    int counter = 0;
    
    cin>>N;
    
    // 인접 노드 입력
    for(int i=1; i<N; i++)
    {
        cin>>src>>dst;
        
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    
    // 시작 노드 입력
    cin>>seq[0];
    visited[seq[0]] = 1;
    
    // 시작 노드가 1인지 체크
    if(seq[0] != 1)
    {
        cout<<0;
        
        return 0;
    }
    
    // 노드 순서 입력하고 체크
    while(n < N)
    {
        counter = 0;
        
        // 지금 부모 모드의 미방문 인접 노드 개수 계산
        for(int i=0; i<graph[seq[id]].size(); i++)
        {
            if(!visited[graph[seq[id]][i]])
            {
                counter++;
            }
        }
        
        // 지금부터 입력하는 n개의 노드가 부모 모드의 미방문 인접 노드인지 체크
        while(counter--)
        {
            cin>>seq[n];
        
            // 미방문 인접 노드 아닌 경우 : 틀린 순서
            if(find(graph[seq[id]].begin(), graph[seq[id]].end(), seq[n]) == graph[seq[id]].end())
            {
                cout<<0;
                
                return 0;
            }
            
            // 방문한 노드를 1로 mark
            visited[seq[n]] = 1;
            
            n++;
        }
        
        // 부모 노드 index를 1로 증가
        id++;
    }
    
    cout<<1;
    
    return 0;
}
